#include "Grafo.h"

namespace ShowCaminhoMinimo
{
	Grafo::Grafo(std::list<int> listaAdjacencia[]) {}

	Grafo::~Grafo() {}
	
	Vertice* Grafo::getVertices() {
		return vertice_;
	}

	Aresta* Grafo::getAresta() {
		return arestas_;
	}
}