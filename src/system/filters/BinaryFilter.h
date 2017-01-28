/*
 * BBHelper.h
 *
 *  Created on: Jun 13, 2016
 *      Author: mbodis
 */

#ifndef SRC_FEATURE_BINARYFILTER_H_
#define SRC_FEATURE_BINARYFILTER_H_

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;


/*
 * Binary methods
 */
class BinaryFilter{
private:

public:
	void fillHoles(Mat*, Mat*, double = 2);
    void removeNoise(Mat*, Mat*, double = 2.0);
    void fillVerticalHoles(Mat*, Mat*, double = 4.0);
    bool hasBBAnyZeros(Mat*, Point, Point);
};




#endif /* SRC_HELPER_BBHELPER_H_ */
