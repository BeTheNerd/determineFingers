#include <algorithm>
#include <iostream>
#include <istream>
#include <ctype.h>
#include "..\include\Leap.h"
#pragma once
using namespace Leap;
class myFingers : public Listener
{
public:
	myFingers(void);
	~myFingers(void);
	virtual void onInit(const Controller&);
	virtual void onConnect(const Controller&);
	virtual void onDisconnect(const Controller&);
	virtual void onExit(const Controller&);
	virtual void onFrame(const Controller&);
	FingerList myFingers::setupFingers(const FingerList& fingers,const Frame& frame);
private:
	Finger rThumb;
	Finger rPointer;
	Finger rMiddle;
	Finger rIndex;
	Finger rPinkie;
	Finger lThumb;
	Finger lPointer;
	Finger lMiddle;
	Finger lIndex;
	Finger lPinkie;
	bool displayMode;
};

