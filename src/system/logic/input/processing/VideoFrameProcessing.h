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

class VideoFrameProcessing : public FrameProcessing{
private:    
    static void runRTV(SourcePath* path);
    
public:
	void start(int, int);

	VideoFrameProcessing(SourcePath* sourcePath, ConfigExample* mConfigExample):
        FrameProcessing(sourcePath, mConfigExample){}
};



#endif /* SRC_LOGIC_FRAME_PROCESSING_VIDEOFRAMEPROCESSING_H_ */
