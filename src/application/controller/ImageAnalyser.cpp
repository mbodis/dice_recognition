

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "ImageAnalyser.h"

#include "DiceAnalyser.h"

using namespace cv;
using namespace std;


ImageAnalyser::ImageAnalyser(ConfigExample *config, int inputMode, int printMode, InputFacade *facade){

    this->mDebugFrames = new DebugFrames(config, inputMode, printMode);
    this->inputMode = inputMode;
    this->printMode = printMode;
    this->facade = facade;

    // TODO initial my logic class
    this->mDiceAnalyser = new DiceAnalyser(this->mDebugFrames);
}

bool ImageAnalyser::analyse(Mat frame, int videoTime) {
    if (frame.dims == 0) return true;

    // TODO execute my logic
    mDiceAnalyser->analyse(frame, videoTime);

    return keyaboardInput(&frame);
}

bool ImageAnalyser::keyaboardInput(Mat *frame){
    // keyboard input action
    char key = (char) waitKey(40);
    mDebugFrames->keyInput(key, frame);
    facade->keyInput(key);
    if (key == 27) return false;
    
    return true;
}

