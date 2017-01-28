

#include "../controllers/ImageAnalyser.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>




using namespace cv;
using namespace std;


ImageAnalyser::ImageAnalyser(ConfigExample *config, int inputMode, int printMode){

    this->mDebugFrames = new DebugFrames(config, inputMode, printMode);
    this->inputMode = inputMode;
    this->printMode = printMode;
}

bool ImageAnalyser::analyse(Mat frame, int videoTime) {
    if (frame.dims == 0) return true;

    executeCustomLogic(frame, videoTime);
//    imshow("frame", frame);

    return keyaboardInput(&frame);
}

bool ImageAnalyser::keyaboardInput(Mat *frame){
    // keyboard input action
    char key = (char) waitKey(40);
    mDebugFrames->keyInput(key, frame);
    if (key == 27) return false;
    
    return true;
}

void ImageAnalyser::executeCustomLogic(Mat frame, int videoTime){
	// TODO initial my logic class
}
