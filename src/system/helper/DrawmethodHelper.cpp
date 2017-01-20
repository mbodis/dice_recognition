/*
 * DrawmethodHelper.cpp
 *
 *  Created on: Jun 14, 2016
 *      Author: mbodis
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace std;
using namespace cv;

#include "DrawMethodHelper.h"

#include "../config/Constants.h"
#include "../../application/config/ConfigExample.h"

/*
 * draw rectangle with color borders
 */
/*void DrawMethodHelper::drawSquareWithPxMMVals(ConfigExample *c, Mat *activeFrame, Point centerP,
		int px, double mm, double WIDE) {

	int border = 2;
	stringstream pxStr, mmStr;
	if (px < 0) {
		pxStr << " - ";
	} else {
		pxStr << px;
		pxStr << " px";
	}
	if (mm < 0) {
		mmStr << " - ";
	} else {
		mmStr << mm;
		mmStr << " mm";
	}

	string txtPx = string("").append(pxStr.str());
	string txtMm = string("").append(mmStr.str());

	// white border
	cv::rectangle(*activeFrame,
			Point(centerP.x - WIDE * c->ROW - border,
					centerP.y - 2 * c->ROW - border),
			Point(centerP.x + WIDE * c->ROW + border, centerP.y + c->ROW + border),
			getSemaphoreBorderColorByValue(px, mm), CV_FILLED);

	// black bg
	cv::rectangle(*activeFrame,
			Point(centerP.x - WIDE * c->ROW, centerP.y - 2 * c->ROW),
			Point(centerP.x + WIDE * c->ROW, centerP.y + c->ROW), colorBlack,
			CV_FILLED);

	// info - px
	cv::putText(*activeFrame, txtPx,
			cvPoint(centerP.x - WIDE * c->ROW, centerP.y - c->ROW),
			FONT_HERSHEY_COMPLEX_SMALL, c->FONT_SIZE_SM, colorWhite, 1,
			CV_AA);

	// info - mm
	cv::putText(*activeFrame, txtMm, cvPoint(centerP.x - WIDE * c->ROW, centerP.y),
			FONT_HERSHEY_COMPLEX_SMALL, c->FONT_SIZE_SM, colorWhite, 1,
			CV_AA);
}*/

/*
 * get semaphore color(green/orange/red) by pixels/milimeters
 */
/*Scalar DrawMethodHelper::getSemaphoreBorderColorByValue(int valuePx, double valueMm) {

	// exception - tyre width
	if (valuePx > 100) {
		return colorMagenta;
	}

	// TODO use mm ?

	if (valuePx == SEMAPHORE_UNDEFINED) {
		return colorWhite;

	} else if (valuePx < SEMAPHORE_RED_PX) {
		return colorGreen;

	} else if (valuePx >= SEMAPHORE_RED_PX) {
		return colorRed;

	}

	return colorWhite;
}

*/