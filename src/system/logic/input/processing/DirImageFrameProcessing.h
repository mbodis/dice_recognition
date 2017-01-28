/*
 * DirImageFrameProcessing.h
 *
 *  Created on: Jul 14, 2016
 *      Author: mbodis
 */

#ifndef SRC_LOGIC_FRAME_PROCESSING_DIRIMAGEFRAMEPROCESSING_H_
#define SRC_LOGIC_FRAME_PROCESSING_DIRIMAGEFRAMEPROCESSING_H_

#include "FrameProcessing.h"
#include "../keyboard/abstract/Move.h"
#include "../../../helper/FileSystemHelper.h"
#include "../../../../application/config/ConfigExample.h"
#include "../../../controllers/ImageAnalyser.h"

using namespace std;


class DirImageFrameProcessing : public FrameProcessing, public Move{
private:
	bool isFinished = false;
	int folderSize;
	int selectedImage;
    bool evaluateNextFrame = true;
    Mat currentFrame;

	FileSystemHelper *mFileSystemHelper;
	string selectedImagePath;

    ImageAnalyser* mImageAnalyser;
public:

	DirImageFrameProcessing(ConfigExample* mConfigExample, ImageAnalyser* mImageAnalyser, SourcePath* sourcePath);

    void start();
	void quit();
    
    void left();
	void right();
	
};



#endif /* SRC_LOGIC_FRAME_PROCESSING_DIRIMAGEFRAMEPROCESSING_H_ */
