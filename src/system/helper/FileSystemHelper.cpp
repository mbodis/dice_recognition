/*
 * Utilities.cpp
 *
 *  Created on: Jun 1, 2016
 *      Author: mbodis
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include <algorithm>
#include <string>
#include <vector>
#include <dirent.h>
#include <sys/types.h>

#include "FileSystemHelper.h"

using namespace std;
using namespace cv;

bool FileSystemHelper::DirectoryExists(const char* pzPath) {
	if (pzPath == NULL)
		return false;

	DIR *pDir;
	bool bExists = false;

	pDir = opendir(pzPath);

	if (pDir != NULL) {
		bExists = true;
		(void) closedir(pDir);
	}

	return bExists;
}

int FileSystemHelper::getNumberFilesInFolder(const char* folderName) {

	int count = 0;

	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(folderName)) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			if (string(ent->d_name).length() > 4) {
				//cout << "file: " << ent->d_name << " lng: " << string(ent->d_name).length() << endl;
				count++;
			}
		}
		closedir(dir);
	} else {
		cout << "folder " << folderName << " does not exists" << endl;
	}

	return count;
}

string FileSystemHelper::getFileInFolder(char* folderName, int selectedFileIdx) {

	int n = 0;
	std::string path = folderName;
	std::string file = "";

	std::vector<std::string> result;
	dirent* de;
	DIR* dp;

	dp = opendir(path.empty() ? "." : path.c_str());
	if (dp) {
		while (true) {

			de = readdir(dp);
			if (de == NULL)
				break;
			result.push_back(std::string(de->d_name));
		}
		closedir(dp);
		std::sort(result.begin(), result.end());
	}
	//return result;
	for (int i = 0; i < result.size(); i++) {
		//cout << "i:" << i << " " << result.at(i) << endl;
		if (result.at(i).length() > 4) {
			if (n == selectedFileIdx) {
				//cout << "select file " << result.at(i) << endl;
				file = result.at(i);
			}
			n++;
		}
	}

	stringstream res;
	res << folderName;
	res << file;

	return res.str();
}

/*
 *
 */
string FileSystemHelper::getFileContent(char* path){
	ifstream inFile;
	inFile.open(path);//open the input file

	stringstream strStream;
	strStream << inFile.rdbuf();//read the file
	return strStream.str();//str holds the content of the file
}


