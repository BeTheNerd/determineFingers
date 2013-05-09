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
	FingerList organizedFingers;
	HandList organizedHands;
	Hand lHand;
	Hand rHand;
	// Grab LeftMost Finger and set that as lPinkie
	lPinkie = currentFingers.leftmost();
	// Grab RightMost Finger and set that as rPinkie
	rPinkie = currentFingers.rightmost();
	// This is the hand associated to lPinkie
	lHand = lPinkie.hand();
	// This is the hand associated to RPinkie
	rHand = rPinkie.hand();
	// Now get the fingers associated with each hand
	FingerList lHandFingers = lHand.fingers();
	FingerList rHandFingers = rHand.fingers();
	// Now get the Thumb associated with left hand
	lThumb = lHandFingers.rightmost();
	// Now get the Thumb associated with the right hand
	rThumb = rHandFingers.leftmost();
	// Now get the Middle finger Associted with Left Hand
	lMiddle = lHandFingers.frontmost();
	// Now get the Middle Finger associated with Right Hand
	rMiddle = rHandFingers.frontmost();
	// Now get List of remaining left hand fingers
	FingerList remainingLeftHandFingers;
	int i = 0;
	for(i;i < lHandFingers.count() ; i++)
	{
		if( lHandFingers[i] != lPinkie && 
		    lHandFingers[i] != lMiddle &&
		    lHandFingers[i] != lThumb  )
		{
		if(remainingLeftHandFingers.count() == 0)
		{
			remainingLeftHandFingers[0] = lHandFingers[i];
		}
		else
		{
			remainingLeftHandFingers[0] = lHandFingers[i];
		}
	}
	}
	// Now check if one is greater then the other
	if(remainingLeftHandFingers[0].tipPosition().x > remainingLeftHandFingers[1].tipPosition().x)
	{
		lPointer = remainingLeftHandFingers[0];
		lIndex = remainingLeftHandFingers[1];
	}
	else
	{
		lIndex = remainingLeftHandFingers[0];
		lPointer = remainingLeftHandFingers[1];
	}
	// Now get List of remaining right hand fingers
	FingerList remainingRightHandFingers;
	i = 0;
	for(i;i < rHandFingers.count() ; i++)
	{
	if( rHandFingers[i] != lPinkie && 
   		rHandFingers[i] != lMiddle &&
		rHandFingers[i] != lThumb  )
	{
	if(remainingRightHandFingers.count() == 0)
	{
		remainingRightHandFingers[0] = rHandFingers[i];
	}
	else
	{
		remainingRightHandFingers[0] = rHandFingers[i];
	}
	}
	}
	// Now check if one is greater then the other
	if(remainingRightHandFingers[0].tipPosition().x < remainingRightHandFingers[1].tipPosition().x)
	{
	rPointer = remainingRightHandFingers[0];
	rIndex = remainingRightHandFingers[1];
	}
	else
	{
		rIndex = remainingRightHandFingers[0];
		rPointer = remainingRightHandFingers[1];
	}
	// Create Lists of organized Objects and add them to the hands and overright
	// the correct Fingers. 
	organizedFingers[0] = lPinkie;
	organizedFingers[1] = lIndex;
	organizedFingers[2] = lMiddle;
	organizedFingers[3] = lPointer;
	organizedFingers[4] = lThumb;
	organizedFingers[5] = rThumb;
	organizedFingers[6] = rPointer;
	organizedFingers[7] = rMiddle;
	organizedFingers[8] = rIndex;
	organizedFingers[9] = rPinkie;
	organizedHands[0] = lHand;
	organizedHands[1] = rHand;
				
				
				return organizedFingers;
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
