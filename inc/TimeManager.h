#pragma once

#include <SDL/SDL_stdinc.h>



struct TimeManager {
private:
	Uint32 m_msPassed;
	double m_delta;
	Uint16 m_fps;
	double m_fpsReal;

	double m_msPerFrame;
	Uint32 m_delayTime;


public:

	TimeManager();

	void  setFps(Uint16 newFPS);
	void  resetDelay();

	void  update();
	void  delay();

	Uint32 getMsPassed();
	double getDelta();
	Uint16 getFps();
	double getFpsReal();
};