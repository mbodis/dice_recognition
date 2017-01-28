/*
 * VideoFrameProcessingLocalCamera.h
 *
 *  Created on: Jan 8, 2017
 *      Author: mbodis
 */

#ifndef SRC_SYSTEM_LOGIC_INPUT_PROCESSING_VIDEOFRAMEPROCESSINGLOCALCAMERA_H_
#define SRC_SYSTEM_LOGIC_INPUT_PROCESSING_VIDEOFRAMEPROCESSINGLOCALCAMERA_H_

#include "../path/SourcePath.h"
#include "FrameProcessing.h"
#include "../../../controllers/ImageAnalyser.h"

class VideoFrameProcessingLocalCamera : public FrameProcessing{
private:
    static void runRTV(SourcePath* path);
    ImageAnalyser* mImageAnalyser;

public:
	VideoFrameProcessingLocalCamera(SourcePath* sourcePath, ConfigExample* mConfigExample, ImageAnalyser* mImageAnalyser):
        FrameProcessing(sourcePath, mConfigExample){
		this->mImageAnalyser = mImageAnalyser;
	}

	void start();
	void startEveryFrame();
};



#endif /* SRC_SYSTEM_LOGIC_INPUT_PROCESSING_VIDEOFRAMEPROCESSINGLOCALCAMERA_H_ */
