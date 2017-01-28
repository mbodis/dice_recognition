/*
 * VideoFrameProcessingRunEveryFrame.h
 *
 *  Created on: Jan 6, 2017
 *      Author: mbodis
 */

#ifndef SRC_SYSTEM_LOGIC_INPUT_PROCESSING_VIDEOFRAMEPROCESSINGRUNEVERYFRAME_H_
#define SRC_SYSTEM_LOGIC_INPUT_PROCESSING_VIDEOFRAMEPROCESSINGRUNEVERYFRAME_H_

#include "FrameProcessing.h"
#include "../keyboard/abstract/Move.h"
#include "../../../helper/FileSystemHelper.h"
#include "../../../../application/config/ConfigExample.h"
#include "../../../controllers/ImageAnalyser.h"

using namespace std;


class VideoFrameProcessingRunEveryFrame : public FrameProcessing{
	private:
		ImageAnalyser *mImageAnalyser;

	public:

		VideoFrameProcessingRunEveryFrame(SourcePath* sourcePath, ConfigExample* mConfigExample, ImageAnalyser* mImageAnalyser):
	        FrameProcessing(sourcePath, mConfigExample){
			this->mImageAnalyser = mImageAnalyser;
		}
		void start();
};

#endif /* SRC_SYSTEM_LOGIC_INPUT_PROCESSING_VIDEOFRAMEPROCESSINGRUNEVERYFRAME_H_ */
