/*
 * TimeHelper.cpp
 *
 *  Created on: May 20, 2016
 *      Author: mbodis
 */

#include "TimeHelper.h"

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <sstream>

using namespace std;


void TimeHelper::resetTimer() {
	gettimeofday(&tp, NULL);
	this->milis = tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

long int TimeHelper::getTimeDiffNowMilis() {

	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	return (ms - this->milis);
}

string TimeHelper::getTimeDiffNowStr() {

	int time = getTimeDiffNowMilis();
	int hours = (time / (1000 * 60 * 60));
	int mins = (time / (1000 * 60)) % 60;
	int seconds = (time / 1000) % 60;
	int miliseconds = (time % 1000);

	stringstream hr, min, sec, mili;
	if (hours < 10) hr << "0";
	if (mins < 10) min << "0";
	if (seconds < 10) sec << "0";
	hr << hours;
	min << mins;
	sec << seconds;
	mili << miliseconds;

	string tt = string("").append(hr.str()).append(":").append(min.str()).append(
					":").append(sec.str()).append(":").append(mili.str());

	return tt;
}
