#pragma once
#include <list>

#include "Vertice.h"

namespace ShowCaminhoMinimo
{
	class Grafo
	{
	private:
		Vertice* vertices_;
		int** matrizPesos_;
		int quantVertices_;
	public:
		Grafo(int** matrizPesos, int quantidadeVertices);
		~Grafo();
		Vertice* getVertices();
		int** getMatrizPesos();
		int getQuantidadeVertices();
		void setGrafo();
	};
}