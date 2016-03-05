#include "../inc/types.h"
#include "../inc/Game.h"









Transform2d::Transform2d() 
	:pos(), size(), rot(0.)
{}
Transform2d::Transform2d(Pos2<double> p, Size2<double> s, double r)
		:pos(p), size(s), rot(r)
{}
Transform2d::Transform2d(double x, double y, double w, double h, double r)
	:pos(x, y), size(w, h), rot(r)
{}
Transform2d& Transform2d::operator<< (const Transform2d rhs) {
	pos += rhs.pos * size;
	size *= rhs.size;
	rot += rhs.rot;

	return *this;
}



Button::Button() 
  : m_state(bt_state::normal),
	m_textureNormal(nullptr),
	m_textureHighlighted(nullptr),
	m_texturePressed(nullptr)
{}
Button::~Button()
{}
void Button::highlight() {
	m_state = bt_state::highlighted;
}
void Button::unhighlight() {
	m_state = bt_state::normal;
}
void Button::press()
{
	m_state = bt_state::pressed;
}
void Button::update() {
}
void Button::render(Transform2d offset) {

	SDL_Texture* toDraw = nullptr;

	switch (m_state)
	{
	case bt_state::normal:
		toDraw = m_textureNormal;
		break;
	case bt_state::highlighted:
		toDraw = m_textureHighlighted;
		break;
	case bt_state::pressed:
		toDraw = m_texturePressed;
		break;
	}

	offset << trans;

	SDL_Rect dst = { static_cast<int>(offset.pos.x),
					 static_cast<int>(offset.pos.y),
					 static_cast<int>(offset.size.x),
					 static_cast<int>(offset.size.y) };

	SDL_RenderCopyEx(game.win.getSdlRenderer(),toDraw,nullptr,&dst,trans.rot,nullptr,SDL_FLIP_NONE);
}
