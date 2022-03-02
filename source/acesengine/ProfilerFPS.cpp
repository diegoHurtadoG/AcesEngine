#include "ProfilerFPS.h"

namespace acesengine {
	ProfilerFPS::ProfilerFPS() : mFrame(0), mFps(0) {}

	const unsigned int ProfilerFPS::getFPS() { 
		return mFps; 
	}

	void ProfilerFPS::update()
	{
		if (mClock.getElapsedTime().asSeconds() >= 1.f)
		{
			mFps = mFrame;
			mFrame = 0;
			mClock.restart();
		}

		++mFrame;
	}

	void ProfilerFPS::draw(AcesWindow& acesWindow)
	{
	}

};