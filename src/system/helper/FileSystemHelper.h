/*
 * Utilities.h
 *
 *  Created on: Jun 1, 2016
 *      Author: mbodis
 */

#ifndef SRC_HELPER_FILESYSTEMHELPER_H_
#define SRC_HELPER_FILESYSTEMHELPER_H_

#include <iostream>
using namespace std;

class FileSystemHelper {
private:

public:
	bool DirectoryExists(const char*);
	int getNumberFilesInFolder(const char*);
	string getFileInFolder(char*, int);
	string getFileContent(char*);

};

#endif /* SRC_HELPER_FILESYSTEMHELPER_H_ */
