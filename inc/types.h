#pragma once
#include <SDL/SDL_render.h>
#include "vec2.h"

template <typename T>
struct Size2 : public vec2<T> {

	Size2();
	Size2(T xx,T yy);
};


template <typename T>
struct Pos2 : public vec2<T> {
	Pos2();
	Pos2(T xx,T yy);
};

template <typename T>
Size2<T>::Size2()
	:vec2<T>(1, 1)
{}
template <typename T>
Size2<T>::Size2(T ww, T hh)
	: vec2<T>(ww, hh)
{}


template <typename T>
Pos2<T>::Pos2()
	:vec2<T>(0, 0)
{}
template <typename T>
Pos2<T>::Pos2(T xx, T yy)
	: vec2<T>(xx, yy)
{}




struct Transform2d {
	Pos2<double>  pos;
	Size2<double> size;
	double        rot;
	Transform2d();
	Transform2d(Pos2<double> p, Size2<double> s, double r);
	Transform2d(double x, double y, double w, double h, double r);
	Transform2d& operator<< (const Transform2d rhs);
};


class GameObject {
public:
	Transform2d trans;
	virtual void update() = 0;
	virtual void render(Transform2d offset = Transform2d()) = 0;
};


enum class bt_state {
	normal,
	highlighted,
	pressed,
};
class Button : public GameObject {
	bt_state     m_state;
	SDL_Texture* m_textureNormal;
	SDL_Texture* m_textureHighlighted;
	SDL_Texture* m_texturePressed;
public:
	Button();
	~Button();
	void highlight();
	void unhighlight();
	void press();
	void update() override;
	void render(Transform2d offset = Transform2d()) override;
};