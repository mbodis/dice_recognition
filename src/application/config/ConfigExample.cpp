/*
 * ConfigExample.cpp
 *
 *  Created on: Jul 11, 2016
 *      Author: mbodis
 */

#include "ConfigExample.h"
#include "../../system/helper/FileSystemHelper.h"

using namespace std;

#include "iostream"
#include "../../libs/json/JSON.h"


/*
 * parse string value by key from JSON structure
 */
string getStrByKey(wstring wkey, JSONObject root){

	string key(wkey.begin(), wkey.end());

	if (root.find(wkey) == root.end() || !root[wkey]->IsString()){
		cout << "json file required " << key << " attr" << endl;
		return "";
	}
	wstring ws = root[wkey]->AsString();
	return string(ws.begin(), ws.end());
}

/*
 * parse number by key from JSON structure
 */
double getNumberByKey(wstring wkey, JSONObject root){

	string key(wkey.begin(), wkey.end());

	if (root.find(wkey) == root.end() || !root[wkey]->IsNumber()){
		cout << "json file required " << key << " attr" << endl;
		return -1;
	}

	return  root[wkey]->AsNumber();
}

/*
 * parse scalar - color scalar
 * 	(json object {"r":123,"g":123,"b":123})
 */
Scalar getScalarByKey(wstring wkey, JSONObject root){

	string key(wkey.begin(), wkey.end());

	if (root.find(wkey) == root.end() || !root[wkey]->IsObject()){
		cout << "json file required " << key << " attr" << endl;
		return Scalar(0,0,0);
	}

	JSONObject obj = root[wkey]->AsObject();
	int b = obj[L"b"]->AsNumber();
	int g = obj[L"g"]->AsNumber();
	int r = obj[L"r"]->AsNumber();

	return  Scalar(b,g,r);
}

/*
 * parse Point from JSON structure
 * 	(json object {"x":45,"y":456}
 */
Point getPointByKey(wstring wkey, JSONObject root){

	string key(wkey.begin(), wkey.end());

	if (root.find(wkey) == root.end() || !root[wkey]->IsObject()){
		cout << "json file required " << key << " attr" << endl;
		return Point(-1, -1);
	}

	JSONObject obj = root[wkey]->AsObject();
	int x = obj[L"x"]->AsNumber();
	int y = obj[L"y"]->AsNumber();

	return  Point(x, y);
}

/*
 * parsing constant form JSON file
 */
ConfigExample::ConfigExample(char* path, int inputMode, int printMode) {

	this->inputMode = inputMode;
	this->printMode = printMode;
	FileSystemHelper mFileSystemHelper;
	string s = mFileSystemHelper.getFileContent(path);
    cout << s << endl;

	char *json_string = (char*) s.c_str();

	JSONObject root, localObj;
	JSONValue *value = JSON::Parse(json_string);

	if (value == NULL) {
		cout << "Json failed to parse: " << s << endl;
	} else {
		root = value->AsObject();

		VIDEO_NAME = string(ASSETS_FOLDER).append(getStrByKey(L"VIDEO_NAME", root));
		FOLDER = string(ASSETS_FOLDER).append(getStrByKey(L"FOLDER", root));
        URL = string().append(getStrByKey(L"URL", root));
        CAMERA_IDX  = getNumberByKey(L"CAMERA_IDX", root);

        // TODO add your constants here

        setFontSize(-1, -1);		
		debugPrintOut();
	}
}

void ConfigExample::initFontSize(Mat *frame){
    if (isFontSizeSet) 
        return;
    
    IMG_WIDTH = frame->cols;
    IMG_HEIGHT = frame->rows;
    setFontSize(IMG_WIDTH, IMG_HEIGHT);
    
    isFontSizeSet = true;
}

void ConfigExample::setFontSize(int width, int height){
    if ( (width == -1 && height == -1) 
        || (width == 1280 && height == 720) ){
        // fonts and line height - 1280:720
        FONT_SIZE = 0.5;
        FONT_SIZE_SM = 0.4;
        ROW = 10; // row height

    }else{
        // fonts and line height - 1920:1080
        FONT_SIZE = 0.8;
        FONT_SIZE_SM = 0.6;
        ROW = 20; // row height
    }
}

void ConfigExample::debugPrintOut(){

	cout << "VIDEO_NAME:" << VIDEO_NAME << endl;
	cout << "FOLDER:" << FOLDER << endl;
	cout << "FOLDER_NAME:" << FOLDER_NAME << endl;
	cout << "URL:" << URL << endl;
	cout << "CAMERA_IDX:" << CAMERA_IDX << endl;

	cout << "FONT_SIZE:" << FONT_SIZE << endl;
	cout << "FONT_SIZE_SM:" << FONT_SIZE_SM << endl;
	cout << "ROW:" << ROW << endl;

}

