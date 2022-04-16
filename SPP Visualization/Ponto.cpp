#include "Ponto.h"

namespace ShowCaminhoMinimo
{
	Ponto::Ponto() {}

	Ponto::Ponto(float X, float Y) {
		X_ = X;
		Y_ = Y;
	}

	Ponto::Ponto(const Ponto& ponto) {
		X_ = ponto.X_;
		Y_ = ponto.Y_;
	}

	Ponto::~Ponto() {}

	float Ponto::getX() {
		return X_;
	}

	float Ponto::getY() {
		return Y_;
	}

	void Ponto::setX(float X) {
		X_ = X;
	}

	void Ponto::setY(float Y) {
		Y_ = Y;
	}
}