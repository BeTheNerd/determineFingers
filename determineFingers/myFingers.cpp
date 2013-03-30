#include "myFingers.h"
#include "..\include\Leap.h"
using namespace Leap;
myFingers::myFingers(void)
{
	displayMode = false;
}

myFingers::~myFingers(void)
{
}

FingerList myFingers::setupFingers(const FingerList& fingers, const Frame& frame) {
	FingerList currentFingers;
	float widthArray[10];
	float lengthArray[10];
	int wPos = 0;
	int count = 10;
	for(int i = 0;i < 10;i++)
	{
		widthArray[i]  = fingers[i].width();
		lengthArray[i] = fingers[i].length();
		if(widthArray[wPos] = fingers[i].width())
		{
			if(wPos == 0) {lPinkie  = fingers[i];currentFingers[0] = lPinkie;}
			if(wPos == 1) {lIndex   = fingers[i];currentFingers[1] = lIndex;}
			if(wPos == 2) {lMiddle  = fingers[i];currentFingers[2] = lMiddle;}
			if(wPos == 3) {lPointer = fingers[i];currentFingers[3] = lPointer;}
			if(wPos == 4) {lThumb   = fingers[i];currentFingers[4] = lThumb;}
			if(wPos == 5) {rThumb   = fingers[i];currentFingers[5] = rThumb;}
			if(wPos == 6) {rPointer = fingers[i];currentFingers[6] = rPointer;}
			if(wPos == 7) {rMiddle  = fingers[i];currentFingers[7] = rMiddle;}
			if(wPos == 8) {rIndex   = fingers[i];currentFingers[8] = rIndex;}
			if(wPos == 9) {rPinkie  = fingers[i];currentFingers[9] = rPinkie;}
		}
		wPos++;
	}
	return currentFingers;
}

void myFingers::onInit(const Controller& controller) {
	std::cout << "Initialized" << std::endl;
}

void myFingers::onConnect(const Controller& controller) {
	std::cout << "Connected" << std::endl;
	std::cout << "Config Mode Initiated: " << std::endl;
	std::cout << "Display Mode?  y/Y or n/N: ";
	char display;
	std::cin >> display;
	if( display == 'y' || display == 'Y' ){
		displayMode = true;
	}
	if( display == 'n' || display == 'N' ){
		displayMode = false;
	}
}

void myFingers::onDisconnect(const Controller& controller) {
	std::cout << "Disconnected" << std::endl;
}

void myFingers::onExit(const Controller& controller) {
	std::cout << "Exited" << std::endl;
}

void myFingers::onFrame(const Controller& controller) {
	FingerList fingers;
	const Frame frame = controller.frame();
	const HandList hands = frame.hands();
	if (!frame.hands().empty()) 
	{
		if( frame.fingers().count() == 10)
		{
			fingers = setupFingers(frame.fingers(),frame);
			if(displayMode)
			{
				std::cout << "Left Hand Fingers  :  " << lThumb.length() <<  " " << lPointer.length() << " " << lMiddle.length() << " " << lIndex.length() << " " <<  lPinkie.length() <<  std::endl;
				std::cout << "Right Hand Fingers :  " << rThumb.length() << " " << rPointer.length() << " " <<  rMiddle.length() << " " << rIndex.length() << " " <<  rPinkie.length() <<  std::endl;
			}
		}
	}
}		
