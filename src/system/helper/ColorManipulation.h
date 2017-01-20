/*
 * ColorManipulation.h
 *
 *  Created on: Jun 21, 2016
 *      Author: jgal
 * source: http://stackoverflow.com/questions/5919663/how-does-photoshop-blend-two-images-together
 */

#ifndef SRC_HELPER_COLORMANIPULATION_H_
#define SRC_HELPER_COLORMANIPULATION_H_

#include <opencv2/core.hpp>
#include <stdint.h>

using namespace cv;
using namespace std;

/*
 * color filter oprerations
 */
class ColorManipulation {
private:

public:
	static void rgb2cmyk(Mat& img, vector<Mat>& cmyk);
	static Mat blend(Mat& img1, Mat& img2, uint8_t (*blendFunction)(uint8_t, uint8_t));
	
	// Blend modes
	static uint8_t ChannelBlend_Normal(uint8_t A, uint8_t B)     { return (A);}
	static uint8_t ChannelBlend_Lighten(uint8_t A, uint8_t B)    { return ((B > A) ? B:A);}
	static uint8_t ChannelBlend_Darken(uint8_t A, uint8_t B)     { return ((B > A) ? A:B);}
	static uint8_t ChannelBlend_Multiply(uint8_t A, uint8_t B)   { return ((A * B) / 255);}
	static uint8_t ChannelBlend_Average(uint8_t A, uint8_t B)    { return ((A + B) / 2);}
	static uint8_t ChannelBlend_Add(uint8_t A, uint8_t B)        { return (min(255, (A + B)));}
	static uint8_t ChannelBlend_Subtract(uint8_t A, uint8_t B)   { return ((A + B < 255) ? 0:(A + B - 255));}
	static uint8_t ChannelBlend_Difference(uint8_t A, uint8_t B) { return (abs(A - B));}
	static uint8_t ChannelBlend_Negation(uint8_t A, uint8_t B)   { return (255 - abs(255 - A - B));}
	static uint8_t ChannelBlend_Screen(uint8_t A, uint8_t B)     { return (255 - (((255 - A) * (255 - B)) >> 8));}
	static uint8_t ChannelBlend_Exclusion(uint8_t A, uint8_t B)  { return (A + B - 2 * A * B / 255);}
	static uint8_t ChannelBlend_Overlay(uint8_t A, uint8_t B)    { return ((B < 128) ? (2 * A * B / 255):(255 - 2 * (255 - A) * (255 - B) / 255));}
	static uint8_t ChannelBlend_SoftLight(uint8_t A, uint8_t B)  { return ((B < 128)?(2*((A>>1)+64))*((float)B/255):(255-(2*(255-((A>>1)+64))*(float)(255-B)/255)));}
	static uint8_t ChannelBlend_HardLight(uint8_t A, uint8_t B)  { return ChannelBlend_Overlay(B,A);}
	static uint8_t ChannelBlend_ColorDodge(uint8_t A, uint8_t B) { return ((B == 255) ? B:min(255, ((A << 8 ) / (255 - B))));}
	static uint8_t ChannelBlend_ColorBurn(uint8_t A, uint8_t B)  { return ((B == 0) ? B:max(0, (255 - ((255 - A) << 8 ) / B)));}
	static uint8_t ChannelBlend_LinearDodge(uint8_t A, uint8_t B){ return ChannelBlend_Add(A,B);}
	static uint8_t ChannelBlend_LinearBurn(uint8_t A, uint8_t B) { return ChannelBlend_Subtract(A,B);}
	static uint8_t ChannelBlend_LinearLight(uint8_t A, uint8_t B){ return (B < 128)?ChannelBlend_LinearBurn(A,(2 * B)):ChannelBlend_LinearDodge(A,(2 * (B - 128)));}
	static uint8_t ChannelBlend_VividLight(uint8_t A, uint8_t B) { return (B < 128)?ChannelBlend_ColorBurn(A,(2 * B)):ChannelBlend_ColorDodge(A,(2 * (B - 128)));}
	static uint8_t ChannelBlend_PinLight(uint8_t A, uint8_t B)   { return (B < 128)?ChannelBlend_Darken(A,(2 * B)):ChannelBlend_Lighten(A,(2 * (B - 128)));}
	static uint8_t ChannelBlend_HardMix(uint8_t A, uint8_t B)    { return ((ChannelBlend_VividLight(A,B) < 128) ? 0:255);}
	static uint8_t ChannelBlend_Reflect(uint8_t A, uint8_t B)    { return ((B == 255) ? B:min(255, (A * A / (255 - B))));}
	static uint8_t ChannelBlend_Glow(uint8_t A, uint8_t B)       { return ChannelBlend_Reflect(B,A);}
	static uint8_t ChannelBlend_Phoenix(uint8_t A, uint8_t B)    { return (min(A,B) - max(A,B) + 255);}
	static uint8_t ChannelBlend_Alpha(uint8_t A, uint8_t B, uint8_t O)    { return (O * A + (1 - O) * B);}
	static uint8_t ChannelBlend_AlphaF(uint8_t A, uint8_t B, uint8_t (*F)(uint8_t, uint8_t), uint8_t O) { return ChannelBlend_Alpha(F(A,B),A,O);}
};

#endif /* SRC_HELPER_COLORMANIPULATION_H_ */