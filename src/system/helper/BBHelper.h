/*
 * BBHelper.h
 *
 *  Created on: Jun 13, 2016
 *      Author: mbodis
 */

#ifndef SRC_HELPER_BBHELPER_H_
#define SRC_HELPER_BBHELPER_H_

#include <opencv2/core.hpp>
#include "../../application/config/ConfigExample.h"
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

/*
 * Bounding Box helper methods
 */
class BBHelper{
private:

public:
	bool isBBFillingAllHeight(Mat*, Rect);
	bool isBBAboveBB(ConfigExample*, Mat*, Rect, Rect);
};




#endif /* SRC_HELPER_BBHELPER_H_ */
