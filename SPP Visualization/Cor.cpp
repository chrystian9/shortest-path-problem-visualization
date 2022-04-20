#include "Cor.h"

namespace ShowCaminhoMinimo
{
	Cor::Cor(){}

	Cor::Cor(float R, float G, float B, float alfa) {
		R_ = R;
		G_ = G;
		B_ = B;
		alfa_ = alfa;
	}

	Cor::Cor(const Cor& cor) {
		R_ = cor.R_;
		G_ = cor.G_;
		B_ = cor.B_;
		alfa_ = cor.alfa_;
	}

	Cor::~Cor() {}

	float Cor::getR() {
		return R_;
	}

	float Cor::getG() {
		return G_;
	}

	float Cor::getB() {
		return B_;
	}

	float Cor::getAlfa() {
		return alfa_;
	}

	void Cor::setR(float R) {
		R_ = R;
	}

	void Cor::setG(float G) {
		G_ = G;
	}

	void Cor::setB(float B) {
		B_ = B;
	}

	void Cor::setAlfa(float alfa) {
		alfa_ = alfa;
	}
}