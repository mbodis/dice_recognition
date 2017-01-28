/*
 * VideoFrameProcessing.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: mbodis
 */

#include "VideoFrameProcessing.h"
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

#include <thread>
#include "../path/SourcePath.h"
#include "../../../controllers/ImageAnalyser.h"
#include "../../../config/Constants.h"

/* SHARED PROCESSING LABEL*/
bool isInputFinished = false;
Mat frameShared, processingFrame;
int videoTimeShared = 0;
bool lockClone = false;
/*
 * sourcePath   ==> path to .avi or url
 * isRT         ==> (RT like Real Time) if is urlPath then have true value
 * */
void VideoFrameProcessing::runRTV(SourcePath *sourcePath) {
	VideoCapture capture;

	capture.set(CV_CAP_PROP_BUFFERSIZE, 1);    
    cout<<"sourcePath->path.c_str(): " << sourcePath->path.c_str() << endl;
	if (!capture.open(sourcePath->path.c_str()))
		throw "Error opening video stream or file";

	while (!isInputFinished) {
        videoTimeShared = capture.get(CV_CAP_PROP_POS_MSEC);  
        if (lockClone) continue;
		if (!capture.read(frameShared)) {
			if (sourcePath->getSourceType() == INPUT_MODE_VIDEO_RT) {
				//end of video
				isInputFinished = true;
			} else if (sourcePath->getSourceType() == INPUT_MODE_URL) {
				//wait for continue
				cv::waitKey();
			} else {
				throw "unexpected situation";
			}                    
		}
	}
}

void VideoFrameProcessing::start() {
        
	thread t(runRTV, sourcePath);

    bool isRunningLocal = true;
	while (!isInputFinished) {
        if (frameShared.dims > 0){         
            lockClone = true;
            processingFrame = frameShared.clone();
            lockClone = false;
            isRunningLocal = mImageAnalyser->analyse(processingFrame, videoTimeShared);
        }        
        
        if (!isRunningLocal){
            isInputFinished  = true;
            break;
        }
    }

	t.join();
}

