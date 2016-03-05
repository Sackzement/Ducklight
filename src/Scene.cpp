#include "../inc/Scene.h"

// ERROR
const Size2<int> Scene::m_aspectR(16, 9);
double Scene::m_scale = 1.;




void Scene::rescale(int w, int h) {
	m_scale = w / m_aspectR.x;
}

Size2<int> Scene::getAspectR() {
	return m_aspectR;
}

double Scene::getScale() {
	return m_scale;
}
