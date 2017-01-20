/*
 * VideoPath.h
 *
 *  Created on: Jul 14, 2016
 *      Author: mbodis
 */

#ifndef SRC_LOGIC_FRAME_PROCESSING_VIDEOPATH_H_
#define SRC_LOGIC_FRAME_PROCESSING_VIDEOPATH_H_

#include "SourcePath.h"
#include "../../../../system/config/Constants.h"

using namespace std;

class VideoPath : public SourcePath{
    
public:
	VideoPath(string path):SourcePath(path){ }
	int getSourceType(){ return INPUT_MODE_VIDEO_RT; };
};


#endif /* SRC_LOGIC_FRAME_PROCESSING_VIDEOPATH_H_ */
