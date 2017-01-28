/*
 * ConfigExample.h
 *
 *  Created on: Jul 11, 2016
 *      Author: mbodis
 */

#ifndef SRC_LOGIC_CONFIGEXAMPLE_H_
#define SRC_LOGIC_CONFIGEXAMPLE_H_

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#include "../../system/config/Constants.h"

using namespace std;


/*
 * TODO desc
 */
class ConfigExample{
private:
    bool isFontSizeSet = false;
public:
	ConfigExample(char*, int, int);
	void debugPrintOut();
    void initFontSize(Mat*);
    void setFontSize(int, int);

	string VIDEO_NAME;
	string FOLDER;
	char* FOLDER_NAME = (char*)FOLDER.c_str();
	int inputMode;
	int printMode;
    string URL;
    int CAMERA_IDX;
    
    int IMG_WIDTH;
	int IMG_HEIGHT;
    
    double FONT_SIZE = 0.5;
	double FONT_SIZE_SM = 0.4;
	int ROW = 10; // row height

};



#endif /* SRC_LOGIC_CONFIGEXAMPLE_H_ */
