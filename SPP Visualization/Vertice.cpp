#include "Vertice.h"

namespace ShowCaminhoMinimo
{
	Vertice::Vertice(VerticeAresta* vizinhos, Cor cor, Textura textura, Ponto centro) {
		vizinhos_ = vizinhos;
		cor_ = cor;
		textura_ = textura;
		centro_ = centro;
	}

	Vertice::~Vertice() {}

	VerticeAresta* Vertice::getVizinhos() {
		return vizinhos_;
	}

	Cor Vertice::getCor() {
		return cor_;
	}

	Textura Vertice::getTextura() {
		return textura_;
	}

	Ponto Vertice::getCentro() {
		return centro_;
	}
	
	void Vertice::setVizinhos(VerticeAresta* vizinhos) {
		vizinhos_ = vizinhos;
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