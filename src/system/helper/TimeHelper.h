/*
 * TimeHelper.h
 *
 *  Created on: May 23, 2016
 *      Author: mbodis
 */

#ifndef SRC_HELPER_TIMEHELPER_H_
#define SRC_HELPER_TIMEHELPER_H_

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>

using namespace std;

class TimeHelper{


private:
	long int milis;
	struct timeval tp; // timestamp

public:
	void resetTimer();
	long int getTimeDiffNowMilis();
	string getTimeDiffNowStr();

};

#endif /* SRC_HELPER_TIMEHELPER_H_ */
