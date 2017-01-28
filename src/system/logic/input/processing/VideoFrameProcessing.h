/*
 * VideoFrameProcessing.h
 *
 *  Created on: Jul 14, 2016
 *      Author: mbodis
 */

#ifndef SRC_LOGIC_FRAME_PROCESSING_VIDEOFRAMEPROCESSING_H_
#define SRC_LOGIC_FRAME_PROCESSING_VIDEOFRAMEPROCESSING_H_

#include "../path/SourcePath.h"
#include "FrameProcessing.h"
#include "../../../controllers/ImageAnalyser.h"

class VideoFrameProcessing : public FrameProcessing{
private:    
    ImageAnalyser *mImageAnalyser;
    static void runRTV(SourcePath* path);
    
public:

	VideoFrameProcessing(SourcePath* sourcePath, ConfigExample* mConfigExample, ImageAnalyser* mImageAnalyser):
        FrameProcessing(sourcePath, mConfigExample){
		this->mImageAnalyser = mImageAnalyser;
	}

	void start();
};



#endif /* SRC_LOGIC_FRAME_PROCESSING_VIDEOFRAMEPROCESSING_H_ */
