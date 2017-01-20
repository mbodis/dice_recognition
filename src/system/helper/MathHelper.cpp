/*
 * MathHelper.cpp
 *
 *  Created on: Jun 27, 2016
 *      Author: mbodis
 */

#include "MathHelper.h"

#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <dirent.h>

using namespace cv;

/*
 * Math get median from vector int
 */
double MathHelper::calcMHWScore(vector<int> scores) {
	if (scores.size() == 0)
		return -1;

	double median;
	size_t size = scores.size();

	sort(scores.begin(), scores.end());

	if (size % 2 == 0) {
		median = (scores[size / 2 - 1] + scores[size / 2]) / 2;
	} else {
		median = scores[size / 2];
	}

	return median;
}


/*
 * comparator for
 */
struct PointCompareYClass {
	bool operator()(cv::Point2f pt1, cv::Point2f pt2) {
		return (pt1.y < pt2.y);
	}
} mPointCompareYClass;

/*
 *
 */
vector<Point2f> MathHelper::sortPointsByYAxe(vector<Point2f> points) {
	std::sort(points.begin(), points.end(), mPointCompareYClass);
	return points;
}

