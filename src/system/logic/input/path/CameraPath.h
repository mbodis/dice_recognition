/*
 * CameraPath.h
 *
 *  Created on: Jan 8, 2017
 *      Author: mbodis
 */

#ifndef SRC_SYSTEM_LOGIC_INPUT_PATH_CAMERAPATH_H_
#define SRC_SYSTEM_LOGIC_INPUT_PATH_CAMERAPATH_H_

using namespace std;
#include "SourcePath.h"
#include "../../../config/Constants.h"

#include <iostream>

class CameraPath :public SourcePath{
public:
	CameraPath(int cameraIdx):SourcePath(cameraIdx){ }
	int getSourceType(){ return INPUT_MODE_LOCAL_CAMERA; }
};



#endif /* SRC_SYSTEM_LOGIC_INPUT_PATH_CAMERAPATH_H_ */
