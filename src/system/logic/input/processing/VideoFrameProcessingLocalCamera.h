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

class VideoFrameProcessingLocalCamera : public FrameProcessing{
private:
    static void runRTV(SourcePath* path);

public:
	void start(int, int);
	void startEveryFrame(int, int);

	VideoFrameProcessingLocalCamera(SourcePath* sourcePath, ConfigExample* mConfigExample):
        FrameProcessing(sourcePath, mConfigExample){}
};



#endif /* SRC_SYSTEM_LOGIC_INPUT_PROCESSING_VIDEOFRAMEPROCESSINGLOCALCAMERA_H_ */
