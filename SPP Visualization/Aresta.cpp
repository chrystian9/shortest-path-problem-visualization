#include "Aresta.h"
#include "Vertice.h"

namespace ShowCaminhoMinimo
{
	Aresta::Aresta(Vertice* verticeA, Vertice* verticeB, Cor cor, bool brilho) {
		verticeA_ = verticeA;
		verticeB_ = verticeB;
		cor_ = cor;
		brilho_ = brilho;
	}

	Aresta::~Aresta() {}
	
	Vertice* Aresta::getVerticeA() {
		return verticeA_;
	}
	
	Vertice* Aresta::getVerticeB() {
		return verticeB_;
	}

	Cor Aresta::getCor() {
		return cor_;
	}

	bool Aresta::isBrilho() {
		return brilho_;
	}

	void Aresta::setCor(Cor cor) {
		cor_ = cor;
	}
}