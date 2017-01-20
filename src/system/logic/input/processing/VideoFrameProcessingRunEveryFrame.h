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
#include "../../../../application/controller/ImageAnalyser.h"

using namespace std;


class VideoFrameProcessingRunEveryFrame : public FrameProcessing{
	private:

	public:
		void start(int, int);

		VideoFrameProcessingRunEveryFrame(SourcePath* sourcePath, ConfigExample* mConfigExample):
	        FrameProcessing(sourcePath, mConfigExample){}
	};



#endif /* SRC_SYSTEM_LOGIC_INPUT_PROCESSING_VIDEOFRAMEPROCESSINGRUNEVERYFRAME_H_ */
