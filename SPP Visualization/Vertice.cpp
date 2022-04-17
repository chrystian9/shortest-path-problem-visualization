#include "Vertice.h"

namespace ShowCaminhoMinimo
{
	Vertice::Vertice() {}

	Vertice::Vertice(Cor cor, Textura textura, Ponto centro) {
		cor_ = cor;
		textura_ = textura;
		centro_ = centro;
	}

	Vertice::~Vertice() {}

	Cor Vertice::getCor() {
		return cor_;
	}

	Textura Vertice::getTextura() {
		return textura_;
	}

	Ponto Vertice::getCentro() {
		return centro_;
	}
	
	void Vertice::setCor(Cor cor) {
		cor_ = cor;
	}
	
	void Vertice::setTextura(Textura textura) {
		textura_ = textura;
	}

	void Vertice::setCentro(Ponto ponto) {
		centro_ = ponto;
	}
}