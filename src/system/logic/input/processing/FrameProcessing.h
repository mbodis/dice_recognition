
#ifndef TYRERECOGNITION_VIDEOFRAMEPROCESSING_H
#define TYRERECOGNITION_VIDEOFRAMEPROCESSING_H

#include <opencv2/highgui/highgui.hpp>
#include "../path/SourcePath.h"
#include "../../../config/Constants.h"
#include "../../../../application/config/ConfigExample.h"


using namespace std;
using namespace cv;


class FrameProcessing {
protected:
	SourcePath* sourcePath;
    ConfigExample* c;

public:

	virtual void start() { throw "Use subclass"; };
	virtual ~FrameProcessing(){ throw "Use subclass"; };

	FrameProcessing(SourcePath* sourcePathInput, ConfigExample* mConfigExample){
        this->sourcePath = sourcePathInput;
        this->c = mConfigExample;
	}
};

#endif //TYRERECOGNITION_RTVFRAMEPROCESSING_H
