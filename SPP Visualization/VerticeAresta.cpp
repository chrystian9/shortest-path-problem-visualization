#include "VerticeAresta.h"

namespace ShowCaminhoMinimo
{
	VerticeAresta::VerticeAresta(Vertice* vertice, Aresta* aresta) {
		vertice_ = vertice;
		aresta_ = aresta;
	}
	
	VerticeAresta::~VerticeAresta() {}
	
	Vertice* VerticeAresta::getVertice() {
		return vertice_;
	}
	
	Aresta* VerticeAresta::getAresta() {
		return aresta_;
	}
	
	void VerticeAresta::setVertice(Vertice* vertice) {
		vertice_ = vertice;
	}
	
	void VerticeAresta::setAresta(Aresta* aresta) {
		aresta_ = aresta;
	}
}