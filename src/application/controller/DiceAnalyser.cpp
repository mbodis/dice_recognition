

#include "DiceAnalyser.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "../../system/helper/TimeHelper.h"


using namespace cv;
using namespace std;


DiceAnalyser::DiceAnalyser(DebugFrames *dDebugFrames){
    this->mDebugFrames = dDebugFrames;

    initTrackball();
}

void DiceAnalyser::initTrackball(){
    namedWindow("tools", 1);
    createTrackbar( "th background", "tools", &sliderThresholdBg, slider_max, on_trackbar);
}


void DiceAnalyser::analyse(Mat frame, int videoTime){

    // save frame
    saveInputFrame(frame, videoTime);
    
    // movement detection
    if (mDebugFrames->c.inputType == INPUT_MODE_IMG_FOLDER){
    	isFrameMoving = false;
    }else{
    	detectMovement(&grayFrame, &lastGrayFrame);
    }

    // find dice
    findDice();

    // debug
    mDebugFrames->drawStatus(&colorFrame, video_time);
    
    // show output
    showOutput();

    saveLastFrame();
}

void DiceAnalyser::detectMovement(Mat *grayFrame1, Mat *grayFrame2){

	Mat diffGray, actualDiffBw;

	if (grayFrame1->dims != 0 && grayFrame2->dims != 0) {

		absdiff(*grayFrame2, *grayFrame1, diffGray);
		actualDiffBw = diffGray > 120; // TODO constant

		double whitePercentage = (double)countNonZero(actualDiffBw) * 100
				/ (grayFrame1->cols * grayFrame1->rows);
//		 cout << "display moves percentage: " << whitePercentage << endl;
//		 cout << "video_time: " << video_time << endl;
//		 cout << "last_move_tim: " << last_move_time << endl;
//		 cout << "----------------------" << endl;
		if (whitePercentage > 0.02) {
			isFrameMoving = true;
			last_move_time = video_time;
		}else{
			if (video_time - last_move_time < 200){
				isFrameMoving = true;
			}else{
				isFrameMoving = false;
			}
		}
	}else{
		isFrameMoving = true;
	}

	string movingTxt = isFrameMoving?"moving":"not moving";
	Scalar color = isFrameMoving?Scalar(0,0,255):Scalar(0,255,0);

	cv::putText(colorFrame, movingTxt, cvPoint(5, 55),
					FONT_HERSHEY_COMPLEX_SMALL, 0.8, color, 1, CV_AA);
}

void DiceAnalyser::findDice(){

	if (!isFrameMoving){

		// blur
		blur(grayFrame, thBinaryFrame, Size( 3, 3 ) );
		thBinaryFrame = thBinaryFrame > sliderThresholdBg;

		//morph
		Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3), Point(1, 1));
		morphologyEx(thBinaryFrame, morphBinaryFrame, MORPH_OPEN, element);

		// dice countours
		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;
		cv::findContours(morphBinaryFrame.clone(), contours, hierarchy, CV_RETR_EXTERNAL,
				CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
//		cout << "dices found contours: " << contours.size() << "------------------" << endl;

		contoursFrame = Mat::zeros( colorFrame.size(), CV_8UC3 );
		for( int i = 0; i< contours.size(); i++ ){
		   drawContours( contoursFrame, contours, i, Scalar(0, 0, 255), 2, 8, hierarchy, 0, Point() );
		   // drawContours( colorFrame, contours, i, Scalar(0, 0, 255), 2, 8, hierarchy, 0, Point() );
		}

		// find rotate rect from contours
		vector<vector<Point> > contoursPoly(contours.size());
		vector<Rect> boundRect(contours.size());
		vector<RotatedRect> minRect( contours.size() );
		for (int i = 0; i < contours.size(); i++) {
			approxPolyDP(Mat(contours[i]), contoursPoly[i], 3, true);
			boundRect[i] = boundingRect(Mat(contoursPoly[i]));
			minRect[i] = minAreaRect( Mat(contours[i]) );
		}

		//draw rotate rect
		for (int i = 0; i < minRect.size(); i++) {
			Point2f rect_points[4];
			minRect[i].points(rect_points);
			if (contours[i].size() < 20) continue;
			for (int i = 0; i < 4; i++) {
				line(colorFrame, rect_points[i], rect_points[(i+1)%4], Scalar(0,0,255), 2);
			}
		}

		// fill background
		uchar fillValue = 255;
		fillMat = Mat::zeros( Size(colorFrame.cols+2, colorFrame.rows+2), morphBinaryFrame.type());
		cv::floodFill(thBinaryFrame, fillMat, Point(4,4), cv::Scalar(255,255,255) ,0,
				cv::Scalar(), cv::Scalar(), 4 | cv::FLOODFILL_MASK_ONLY | (fillValue << 8));
		// resize fill area back to frame size
		cv::Rect area(1, 1, colorFrame.cols, colorFrame.rows);
		fillMat = fillMat(area);
		bitwise_or(thBinaryFrame, fillMat, fillMat);
		bitwise_not(fillMat, fillMat);

		int totalCount = 0;
		// dots countours
		for (int i = 0; i < contours.size(); i++) {
			int dotCount = 0;
//			 cout << "contours[i].size(): " << contours[i].size() << endl;
			if (contours[i].size() < 20) continue;

			// crop
			Mat m = Mat::zeros( fillMat.size(), fillMat.type() );
			m = fillMat(boundRect[i]);

			vector<vector<Point> > contoursDots;
			vector<Vec4i> hierarchyDots;
			cv::findContours(m.clone(), contoursDots, hierarchyDots, CV_RETR_EXTERNAL,
					CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
//			cout << "dice:" << i << " contoursDots: " << contoursDots.size() << " XXXX "<< endl;

			// dice dots bounding boxes
			vector<vector<Point> > contoursPolyDots(contoursDots.size());
			vector<Rect> boundRectDots(contoursDots.size());
			vector<RotatedRect> minRectDots( contoursDots.size() );
			for (int j = 0; j < contoursDots.size(); j++) {
				approxPolyDP(Mat(contoursDots[j]), contoursPolyDots[j], 3, true);
				boundRectDots[j] = boundingRect(Mat(contoursPolyDots[j]));
				minRectDots[j] = minAreaRect( Mat(contoursDots[j]) );
//				cout << "contoursDots[j].size(): " << contoursDots[j].size()
//						<< " w:" << boundRectDots[j].width << " h:" << boundRectDots[j].height << " ||| "
//						<< " w2: " << minRectDots[j].size.width << " h2: " << minRectDots[j].size.height
//						<< endl;

				double ratio1 = (double) boundRectDots[j].width / boundRectDots[j].height;
				double ratio2 = (double) boundRectDots[j].height / boundRectDots[j].width;
				double ratio = fmax(ratio1, ratio2);

				double rratio1 = (double) minRectDots[j].size.width / minRectDots[j].size.height;
				double rratio2 = (double) minRectDots[j].size.height / minRectDots[j].size.width;
				double rratio = fmax(rratio1, rratio2);


//				cout << "ratio: " << ratio <<  "|||" << "rratio: " << rratio << endl;
				if (ratio <= 1.5 && rratio <= 1.5){

					int centerX = boundRect[i].x + boundRectDots[j].x + boundRectDots[j].height/2;
					int centerY = boundRect[i].y + boundRectDots[j].y + boundRectDots[j].height/2;
					int radius = boundRectDots[j].height/2;

					circle(colorFrame,Point(centerX, centerY), radius, Scalar(0,255,0), -1);
					dotCount++;
				}

			}
//			stringstream counter;
//			counter << "dots: " << i;
//			imshow(counter.str(), m);
//			cout << "DICE: "  << i << " = " << dotCount << endl;

			stringstream txtCounter;
			txtCounter << dotCount;

			totalCount += dotCount;

			double alpha = 0.3;
			Mat overlay = colorFrame.clone();
			Point start = Point(boundRect[i].x, boundRect[i].y + boundRect[i].height +35);
			Point end = Point(boundRect[i].x + boundRect[i].width, boundRect[i].y + boundRect[i].height +5);
			Point startTxt = Point(boundRect[i].x + boundRect[i].height/2, boundRect[i].y + boundRect[i].height +25);

			cv::rectangle(overlay, start, end, colorBlack, CV_FILLED);
			addWeighted(overlay, alpha, colorFrame, 1 - alpha, 0, colorFrame);

			cv::putText(colorFrame, txtCounter.str(), startTxt,
							FONT_HERSHEY_COMPLEX_SMALL, 0.65, colorWhite, 1, CV_AA);

		}

		stringstream totalCounter;
		totalCounter << totalCount;

		// output
		cv::putText(colorFrame, totalCounter.str(), Point(colorFrame.cols - 80, 40), FONT_HERSHEY_COMPLEX_SMALL, 1.35, colorWhite, 1, CV_AA);

//		cout << "--------------" << endl;
	}
}

void DiceAnalyser::saveInputFrame(Mat frame, int videoTime){
    if (resizedWidth == -1 || resizedHeight == -1){
        resizedWidth = frame.cols/resizeRatio;
        resizedHeight = frame.rows/resizeRatio;
    }
    
    if (resiseInput){
        resize(frame, frame, Size(resizedWidth, resizedHeight));
    }
    
    this->colorFrame = frame;
    this->video_time = videoTime;
    cvtColor(colorFrame, grayFrame, CV_BGR2GRAY);
    equalizeHist(grayFrame, grayFrame);
    
    // save img size and setup font size
    mDebugFrames->c.initFontSize(&frame);
}

void DiceAnalyser::saveLastFrame(){
    lastGrayFrame = grayFrame.clone();
}


void DiceAnalyser::showOutput(){
    this->showImg(colorFrame, "original color");
//    this->showImg(grayFrame, "gray color");
//    this->showImg(thBinaryFrame, "thBinaryFrame");
//    this->showImg(morphBinaryFrame, "morphBinaryFrame");
//    this->showImg(contoursFrame, "contoursFrame");
//    this->showImg(fillMat, "fillMat");
//    this->showImg(contoursDotsFrame, "contoursDotsFrame");

}

void DiceAnalyser::showImg(Mat frame, String frameName){
	if (frame.dims != 0) {
		imshow(frameName, frame);
	} else {
		cout << frameName << " is EMPTY !" << endl;
	}
}
