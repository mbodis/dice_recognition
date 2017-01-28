/*
 * ProcessingFacade.h
 *
 *  Created on: Jul 14, 2016
 *      Author: mbodis
 */

#ifndef SRC_LOGIC_PROCESSINGFACADE_H_
#define SRC_LOGIC_PROCESSINGFACADE_H_

#include "../../../application/config/ConfigExample.h"
#include "../../controllers/ImageAnalyser.h"

using namespace std;

class ProcessingFacade{    
    
private:
    
    void runDirImageFrameProcessing();
	void runVideoFrameProcessing();
    void runVideoFrameProcessingRunEveryFrame();
	void runURLVideoFrameProcessing();    
	void runLocalCameraFrameProcessing();
	void runImageAnalyse();
    
public:
	ConfigExample *mConfigExample;
	ImageAnalyser *mImageAnalyser;
	ProcessingFacade(ConfigExample*, ImageAnalyser*);
    
    void runAnalyse();
};



#endif /* SRC_LOGIC_PROCESSINGFACADE_H_ */
