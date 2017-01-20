
#ifndef DICEANALYSER_H
#define DICEANALYSER_H


#include "DebugFrames.h"
#include "../../system/logic/input/keyboard/InputFacade.h"
#include "../../system/features/BinaryFilter.h"
#include "../config/ConfigExample.h"

/*
 * custom application logic 
 */
class DiceAnalyser{
    
private:
    
    int video_time = 0;
    int last_move_time = 0;
    bool resiseInput = true;

    double resizeRatio = 2;
    int resizedWidth = -1;
    int resizedHeight = -1;
    
    // BGR original frame
    Mat colorFrame;
    // gray scale frame
    Mat grayFrame;
    // previous gray scale frame
    Mat lastGrayFrame;
    Mat thBinaryFrame;
    Mat morphBinaryFrame;
	Mat contoursFrame;
	Mat fillMat;
	Mat contoursDotsFrame;
    
    //logic
    bool isFrameMoving = true;

    DebugFrames* mDebugFrames;
    
public:
    
    DiceAnalyser(DebugFrames*);
    
    void analyse(Mat, int);
    void saveLastFrame();

    
    void setFrame(Mat, int);
    void showImg(Mat, String);
    bool keyaboardInput();
    
    //logic
    
    void saveInputFrame(Mat, int);
    void detectMovement(Mat*, Mat*);
    void findDice();
    
    void showOutput();

    // GUI trackball slider
	const int slider_max = 255;
	int sliderThresholdBg = 210;
	void initTrackball();
	static void on_trackbar( int val, void* ){
		// this is not necessary
		//cout<< "v: "<< val << endl;
	}

};


#endif //DICEANALYSER_H
