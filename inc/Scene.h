#pragma once
#include <vector>
#include <SDL/SDL_events.h>


struct Pos2d {
	double x,y;
	Pos2d() :x(0.),y(0.) {}
	Pos2d(double xx,double yy) :x(xx),y(yy) {}
};
struct Size2d {
	double w = 0.,
		   h = 0.;
	Size2d() :w(1.),h(1.) {}
	Size2d(double ww,double hh) :w(ww),h(hh) {}
};

struct Transform2d {
	Pos2d   pos;
	Size2d  size;
	double  rot;
	Transform2d() :pos(),size(),rot(0.) {}
	Transform2d(Pos2d p,Size2d s,double r) 
		:pos(p),size(s),rot(r) {}
	Transform2d(double x,double y,double w,double h,double r) 
		:pos(x,y),size(w,h),rot(r) {}
};


class GameObject {

	Transform2d trans;
	virtual void update() = 0;
	virtual void render() = 0;
};

class Scene : public GameObject {

	static Size2d m_res;

public:
	virtual void load() = 0;
	virtual void input(std::vector<SDL_Event>* events) = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void unload() = 0;
};

