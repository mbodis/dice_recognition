/*
 * ColorManipulation.cpp
 *
 *  Created on: Jun 21, 2016
 *      Author: jgal
 */

#include <iostream>
#include "ColorManipulation.h"

// RGB to CMYK conversion
void ColorManipulation::rgb2cmyk(cv::Mat& img, std::vector<cv::Mat>& cmyk) {
    // Allocate cmyk to store 4 componets
    for (int i = 0; i < 4; i++) {
        cmyk.push_back(cv::Mat(img.size(), CV_8UC1));
    }

    // Get rgb
    std::vector<cv::Mat> rgb;
    cv::split(img, rgb);

    // rgb to cmyk
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            float r = (int)rgb[2].at<uchar>(i, j) / 255.;
            float g = (int)rgb[1].at<uchar>(i, j) / 255.;
            float b = (int)rgb[0].at<uchar>(i, j) / 255.;
            float k = std::min(std::min(1- r, 1- g), 1- b);         
 
            cmyk[0].at<uchar>(i, j) = (1 - r - k) / (1 - k) * 255.;
            cmyk[1].at<uchar>(i, j) = (1 - g - k) / (1 - k) * 255.;
            cmyk[2].at<uchar>(i, j) = (1 - b - k) / (1 - k) * 255.;
            cmyk[3].at<uchar>(i, j) = k * 255.;
        }
    }
}


Mat ColorManipulation::blend(Mat& img1, Mat& img2, uint8_t (*blendFunction)(uint8_t, uint8_t)) {
	Mat blendResult = Mat(img1.size(), CV_8UC1);
	
	if(img1.rows != img2.rows || img1.cols != img2.cols) {
		return blendResult;
	}
	
    for(int y = 0; y < img1.rows; y++) {
		for(int x = 0; x < img1.cols; x++) {
			blendResult.at<uchar>(y, x) = blendFunction(img2.at<uchar>(y, x), img2.at<uchar>(y, x));
		}
	}
	
	return blendResult;
}
