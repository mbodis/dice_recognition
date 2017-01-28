/*
 * DebugFrames.h
 *
 *  Created on: May 23, 2016
 *      Author: mbodis
 */

#ifndef SRC_LOGIC_DEBUGFRAMES_H_
#define SRC_LOGIC_DEBUGFRAMES_H_

#include <opencv2/highgui/highgui.hpp>

#include "../../system/config/Constants.h"
#include "../../system/helper/FileSystemHelper.h"
#include "../../application/config/ConfigExample.h"

using namespace std;
using namespace cv;

/*
 * debug options:
 * - toggle between multiple filters, images, pre-processed states
 * - draw status information on video
 * - draw video time, image name
 */
class DebugFrames {

private:
	
    // save output
    FileSystemHelper mFileSystemHelper;
	int imageSaveCounter = 0;

	// mode
	int typePrintInfo = PRINT_MODE_DEBUG;	
	bool debugWindow = false;	

    // config    
    int INPUT_MODE;

    void drawStatusTime(Mat*, int);
	void printDebugInfo(Mat*);
	void printPresentationInfo(Mat*);
    
public:
    ConfigExample *c;

	DebugFrames(ConfigExample*, int, int);
	~DebugFrames(void);
	
	void drawStatus(Mat*, int);
	void saveFrameToFile(Mat*);
    void keyInput(char, Mat*);

    void toggleDebugWindow();
};


#endif /* SRC_LOGIC_DEBUGFRAMES_H_ */
