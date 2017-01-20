/*
 * Constants.h
 *
 *  Created on: May 6, 2016
 *      Author: mbodis
 */


#ifndef SRC_CONFIG_CONSTANTS_H_
#define SRC_CONFIG_CONSTANTS_H_

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

static char* ASSETS_FOLDER = "../assets_opencv/";

static int INPUT_MODE_IMG_FOLDER = 1;
static int INPUT_MODE_VIDEO_RT = 2;
static int INPUT_MODE_VIDEO_FRAME = 3;
static int INPUT_MODE_URL = 4;
static int INPUT_MODE_LOCAL_CAMERA = 5;

static int PRINT_MODE_DEBUG = 0;
static int PRINT_MODE_PRESENTATION = 1;

// size for presentation
static int IMG_WIDTH_OUT = 1280;
static int IMG_HEIGHT_OUT = 720;

// BGR (blue-green-red) model
static Scalar colorRed = Scalar(0, 0, 255);
static Scalar colorGreen = Scalar(0, 255, 0);
static Scalar colorBlue = Scalar(255, 0, 0);
static Scalar colorWhite = Scalar(255, 255, 255);
static Scalar colorBlack = Scalar(0, 0, 0);
static Scalar colorGray = Scalar(128, 128, 128);
static Scalar colorYellow = Scalar(0, 255, 255);
static Scalar colorMagenta = Scalar(255, 0, 255);
static Scalar colorCyan = Scalar(255, 255, 0);
static Scalar colorOrange = Scalar(0, 140, 255);
static char* OUTPUT_FOLDER = "output/";
static char* OUTPUT_VIDEO_NAME = "out.avi";

#endif /* SRC_CONFIG_CONSTANTS_H_ */
