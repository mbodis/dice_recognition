/*
 * DirPath.h
 *
 *  Created on: Jul 14, 2016
 *      Author: mbodis
 */

#ifndef SRC_LOGIC_FRAME_PROCESSING_DIRPATH_H_
#define SRC_LOGIC_FRAME_PROCESSING_DIRPATH_H_

using namespace std;
#include "SourcePath.h"
#include "../../../../system/config/Constants.h"

class DirPath : public SourcePath{
public:
	DirPath(string path):SourcePath(path){}
	int getSourceType(){ return INPUT_MODE_IMG_FOLDER; }
};



#endif /* SRC_LOGIC_FRAME_PROCESSING_DIRPATH_H_ */
