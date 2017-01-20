/*
 * VideoFrameProcessingRunEveryFrame.cpp
 *
 *  Created on: Jan 6, 2017
 *      Author: mbodis
 */

#include "VideoFrameProcessingRunEveryFrame.h"
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

#include <thread>
#include "../path/SourcePath.h"
#include "../../../../application/controller/ImageAnalyser.h"
#include "../../../config/Constants.h"

void VideoFrameProcessingRunEveryFrame::start(int inputMode, int printMode) {

	VideoCapture capture;

	capture.set(CV_CAP_PROP_BUFFERSIZE, 1);
	if (!capture.open(c->VIDEO_NAME))
		throw "Error opening video stream or file";

	ImageAnalyser analyser(c, inputMode, printMode,
			new InputFacade(new Move()));

	int v_ts;
	Mat mat;

	bool isRunning = true;
	while(isRunning){
		if (!capture.isOpened()) { //check if video device has been initialized
			cout << "cannot open video file" << endl;
			isRunning = false;
		}else{
			v_ts = capture.get(CV_CAP_PROP_POS_MSEC);
			capture >> mat;
			if (mat.dims == 0){
				cout << "end of video file" << endl;
				break;
			}
			isRunning = analyser.analyse(mat, v_ts);
		}
	}
}


