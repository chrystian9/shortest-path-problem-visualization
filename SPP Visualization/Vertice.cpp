#include "Vertice.h"

namespace ShowCaminhoMinimo
{
	Vertice::Vertice() {}

	Vertice::Vertice(Cor cor, Ponto centro) {
		cor_ = cor;
		centro_ = centro;
	}

	Vertice::~Vertice() {}

	Cor Vertice::getCor() {
		return cor_;
	}

	Ponto Vertice::getCentro() {
		return centro_;
	}
	
	void Vertice::setCor(Cor cor) {
		cor_ = cor;
	}

	void Vertice::setCentro(Ponto ponto) {
		centro_ = ponto;
	}
}