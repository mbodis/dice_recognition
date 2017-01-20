/*
 * SourcePath.h
 *
 *  Created on: Jul 14, 2016
 *      Author: mbodis
 */

#ifndef SRC_LOGIC_FRAME_PROCESSING_SOURCEPATH_H_
#define SRC_LOGIC_FRAME_PROCESSING_SOURCEPATH_H_

#include <iostream>

using namespace std;

class SourcePath{
public:

	string path;
	int cameraIdx = 0;

	SourcePath(string pathInput){
            this->path = pathInput;
    }

	SourcePath(int cameraIdx){
			this->cameraIdx = cameraIdx;
	}

	virtual int getSourceType(){ throw "Use subclass"; };
	virtual ~SourcePath(){ throw "Use subclass"; };
};


#endif /* SRC_LOGIC_FRAME_PROCESSING_SOURCEPATH_H_ */
