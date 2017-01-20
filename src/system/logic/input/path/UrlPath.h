/*
 * UrlPath.h
 *
 *  Created on: Jul 14, 2016
 *      Author: mbodis
 */

#ifndef SRC_LOGIC_FRAME_PROCESSING_URLPATH_H_
#define SRC_LOGIC_FRAME_PROCESSING_URLPATH_H_

using namespace std;
#include "SourcePath.h"
#include "../../../config/Constants.h"

#include <iostream>

class UrlPath :public SourcePath{
public:
	UrlPath(string path):SourcePath(path){ }
	int getSourceType(){ return INPUT_MODE_URL; }
};

#endif /* SRC_LOGIC_FRAME_PROCESSING_URLPATH_H_ */
