/*
 * DebugFrames.cpp
 *
 *  Created on: May 19, 2016
 *      Author: mbodis
 */

#include "../controllers/DebugFrames.h"

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "../../system/helper/FileSystemHelper.h"
#include "../../system/helper/DrawMethodHelper.h"


#include <iostream>

using namespace std;
using namespace cv;

/*
 * constructor
 * mode [MODE_VIDEO, MODE_IMG_FOLDER, MODE_IMG]
 * typePrintInfo [PRINT_MODE_DEBUG, PRINT_MODE_PRESENTATION]
 */
DebugFrames::DebugFrames(ConfigExample *mConfigExample, int mode, int typePrintInfo) {
	cout << "Object DebugFrames is being created" << endl;
    this->c = mConfigExample;
    this->INPUT_MODE = mode;
	this->typePrintInfo = typePrintInfo;
	if (!mFileSystemHelper.DirectoryExists(OUTPUT_FOLDER)) {
		cout
				<< "missing output folder, please create empty folder in project directory: "
				<< OUTPUT_FOLDER << endl;
	}
}

/* destructor */
DebugFrames::~DebugFrames(void) {
	cout << "Object DebugFrames is being deleted" << endl;
}

/*
 * toggle between multiple filters/modes
 */
void DebugFrames::keyInput(char key, Mat *frame) {
	switch (key) {

	case 's':
		saveFrameToFile(frame);
		break;

	case 'd':
		toggleDebugWindow();
		break;
    }	
}

void DebugFrames::saveFrameToFile(Mat *frame) {

	imageSaveCounter++;
	stringstream fileName;
	fileName << OUTPUT_FOLDER;
	fileName << "out_save_";
	if (imageSaveCounter < 10) {
		fileName << "0";
	}
	fileName << imageSaveCounter;
	fileName << ".jpg";
	imwrite(fileName.str(), *frame);
}

/*
 * status debug
 *  - shows all internal states in debug window
 *  - shows key options
 *
 * status presentation:
 * 	- shows only necessary informations
 */
void DebugFrames::drawStatus(Mat *frame, int time) {
            
    // time status
	drawStatusTime(frame, time);
            
	// debug mode
	if (this->typePrintInfo == PRINT_MODE_DEBUG) {
		printDebugInfo(frame);
        
    // presentation mode
    }else if (this->typePrintInfo == PRINT_MODE_PRESENTATION) {		
        printPresentationInfo(frame);
	}	

}

/*
 * draw debug information on left side of screen
 * frame - image frame do be status drawn
 */
void DebugFrames::printDebugInfo(Mat *frame) {

	if (debugWindow) {

		int row = 3 * c->ROW;

		cv::rectangle(*frame, cvPoint(0, 1.5 * c->ROW), cvPoint(350, frame->rows),
				colorBlack,
				CV_FILLED);
	}
}

/*
 * draw information on left side of screen
 * frame - image frame do be status drawn
 */
void DebugFrames::printPresentationInfo(Mat *frame){
    
}

void DebugFrames::drawStatusTime(Mat *frame, int time) {

	cv::rectangle(*frame, cvPoint(0, 0), cvPoint(350, 1.5 * c->ROW), colorBlack,
	CV_FILLED);

	int hours = (time / (1000 * 60 * 60));
	int mins = (time / (1000 * 60)) % 60;
	int seconds = (time / 1000) % 60;
	int milis = (time % 1000);

	stringstream hr, min, sec, mili;
	if (hours < 10)
		hr << "0";
	if (mins < 10)
		min << "0";
	if (seconds < 10)
		sec << "0";
	hr << hours;
	min << mins;
	sec << seconds;
	mili << milis;

	if (INPUT_MODE == INPUT_MODE_VIDEO_RT || INPUT_MODE == INPUT_MODE_VIDEO_FRAME) {
        string strTime =
			string("video: ").append(hr.str()).append(":").append(min.str()).append(
					":").append(sec.str()).append(":").append(mili.str());
		cv::putText(*frame, strTime, cvPoint(5, c->ROW), FONT_HERSHEY_COMPLEX_SMALL,
				c->FONT_SIZE, colorWhite, 1,
				CV_AA);
                
    } else if (INPUT_MODE == INPUT_MODE_URL) {
		cv::putText(*frame, string("url: ").append(c->URL), cvPoint(5, c->ROW),
				FONT_HERSHEY_COMPLEX_SMALL, c->FONT_SIZE, colorWhite, 1,
				CV_AA);
        
	} else if (INPUT_MODE == INPUT_MODE_IMG_FOLDER) {
		cv::putText(*frame,
				string("folder: ").append(
						c->FOLDER), cvPoint(5, c->ROW),
				FONT_HERSHEY_COMPLEX_SMALL, c->FONT_SIZE, colorWhite, 1,
				CV_AA);
	}
}

void DebugFrames::toggleDebugWindow() {
	this->debugWindow = !this->debugWindow;
}


