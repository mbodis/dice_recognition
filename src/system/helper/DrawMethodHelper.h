/*
 * DrawMethodHelper.h
 *
 *  Created on: Jun 14, 2016
 *      Author: mbodis
 */

#ifndef SRC_HELPER_DRAWMETHODHELPER_H_
#define SRC_HELPER_DRAWMETHODHELPER_H_

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../../application/config/ConfigExample.h"

using namespace cv;

/*
 * canvas drawing helper methods
 */
class DrawMethodHelper{
private:

public:
	Scalar getSemaphoreBorderColorByValue(int, double);
	void drawSquareWithPxMMVals(ConfigExample*, Mat*, Point, int, double, double);

};





#endif /* SRC_HELPER_DRAWMETHODHELPER_H_ */
