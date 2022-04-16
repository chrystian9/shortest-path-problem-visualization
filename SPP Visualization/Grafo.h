#pragma once
#include <list>

#include "Vertice.h"
#include "Aresta.h"

namespace ShowCaminhoMinimo
{
	class Grafo
	{
	private:
		Vertice* vertice_;
		Aresta* arestas_;
	public:
		Grafo(std::list<int> listaAdjacencia[]);
		~Grafo();
		Vertice* getVertices();
		Aresta* getAresta();
	};
}