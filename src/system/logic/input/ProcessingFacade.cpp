/*
 * ProcessingFacade.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: mbodis
 */

#include "ProcessingFacade.h"
#include "../../config/Constants.h"
#include "../../../application/config/ConfigExample.h"
#include "processing/DirImageFrameProcessing.h"
#include "processing/VideoFrameProcessing.h"
#include "processing/VideoFrameProcessingRunEveryFrame.h"
#include "processing/VideoFrameProcessingLocalCamera.h"
#include "path/DirPath.h"
#include "path/VideoPath.h"
#include "path/UrlPath.h"
#include "path/CameraPath.h"

ProcessingFacade::ProcessingFacade(ConfigExample *mConfigExample, ImageAnalyser *mImageAnalyser) {
    this->mConfigExample = mConfigExample;
    this->mImageAnalyser = mImageAnalyser;
}

/*
 * run analyze by selected mode
 */
void ProcessingFacade::runAnalyse() {

    if (this->mConfigExample->inputMode == INPUT_MODE_IMG_FOLDER){
        runDirImageFrameProcessing();
        
    }else if (this->mConfigExample->inputMode == INPUT_MODE_VIDEO_RT){
        runVideoFrameProcessing();
        
    }else if (this->mConfigExample->inputMode == INPUT_MODE_VIDEO_FRAME){
        runVideoFrameProcessingRunEveryFrame();        
        
    }else if (this->mConfigExample->inputMode == INPUT_MODE_URL){
        runURLVideoFrameProcessing();
        
    }else if (this->mConfigExample->inputMode == INPUT_MODE_LOCAL_CAMERA){
    	runLocalCameraFrameProcessing();

    }else{
        cout << "Processing facade: unsupported input type" << endl;
    }
    
}

/*
 * input from folder with multiple images
 */
void ProcessingFacade::runDirImageFrameProcessing() {
    (new DirImageFrameProcessing(mConfigExample, mImageAnalyser, new DirPath(mConfigExample->FOLDER)))
    		->start();
}

/*
 * video input from file - real time
 */
void ProcessingFacade::runVideoFrameProcessing() {
	(new VideoFrameProcessing(new VideoPath(mConfigExample->VIDEO_NAME), mConfigExample, mImageAnalyser))
			->start();
}

/*
 * video input from file - analyze on every frame
 */
void ProcessingFacade::runVideoFrameProcessingRunEveryFrame() {
	(new VideoFrameProcessingRunEveryFrame(new VideoPath(mConfigExample->VIDEO_NAME), mConfigExample, mImageAnalyser))
			->start();
}

/*
 * video input from url
 */
void ProcessingFacade::runURLVideoFrameProcessing() {
	(new VideoFrameProcessing(new UrlPath(mConfigExample->URL), mConfigExample, mImageAnalyser))
			->start();
}

/*
 * video input from local camera/usb camera
 */
void ProcessingFacade::runLocalCameraFrameProcessing() {
	(new VideoFrameProcessingLocalCamera(new CameraPath(mConfigExample->CAMERA_IDX), mConfigExample, mImageAnalyser))
			->start();
//	(new VideoFrameProcessingLocalCamera(new CameraPath(mConfigExample->CAMERA_IDX), mConfigExample, mImageAnalyser))
//			->startEveryFrame();
}
