
#include "../inc/TimeManager.h"
#include <SDL/SDL_timer.h>


TimeManager::TimeManager()

	: m_msPassed(0),
	m_delta(0.),
	m_fps(60),
	m_fpsReal(60.),

	m_msPerFrame(1000. / double(m_fps)),
	m_delayTime(0)
{}

void    TimeManager::setFps(Uint16 newFPS) {

	m_fps = newFPS;
	m_msPerFrame = 1000. / double(m_fps);
}

void    TimeManager::resetDelay() {

	m_delayTime = m_msPassed;
}


void    TimeManager::update() {

	Uint32 lastGameTime = m_msPassed;
	m_msPassed = SDL_GetTicks();

	double diff = double(m_msPassed - lastGameTime);
	m_delta = .001 * diff;
	m_fpsReal = 1000. / diff;
}

void    TimeManager::delay() {

	Uint32 lastDelayTime = m_delayTime;
	m_delayTime = SDL_GetTicks();

	double diff = double(m_delayTime - lastDelayTime);

	if (diff < m_msPerFrame)
		SDL_Delay(Uint32(m_msPerFrame - diff));

	m_delayTime = SDL_GetTicks();
}

Uint32 TimeManager::getMsPassed() {
	return m_msPassed;
}
double TimeManager::getDelta() {
	return m_delta;
}
Uint16 TimeManager::getFps() {
	return m_fps;
}
double TimeManager::getFpsReal() {
	return m_fpsReal;
}