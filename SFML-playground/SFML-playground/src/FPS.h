#ifndef FPS_H
#define FPS_H

class FPS
{
public:
	FPS() : mFrame(0), mFps(0) {}
	void update();
	const unsigned int getFPS() const { return mFps; }

private:
	unsigned int mFrame;
	unsigned int mFps;
	sf::Clock mClock;
};

void FPS::update()
{
	if (mClock.getElapsedTime().asMilliseconds() >= 1000.f)
	{
		mFps = mFrame;
		mFrame = 0;
		mClock.restart();
	}

	++mFrame;
}

#endif