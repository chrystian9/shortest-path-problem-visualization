#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#pragma once

#include "AlgoritmoCaminhoMinimo.h"
#include "Grafo.h"

namespace ShowCaminhoMinimo
{
	class AlgoritmoCaminhoMinimo;
	class Dijkstra
	{
	private:
		static Dijkstra* instancia_;
		Dijkstra();
		static int minDistance(int dist[], bool sptSet[], int quantidadeVertices);
	public:
		~Dijkstra();
		static Dijkstra* getInstancia();
		void showDijkstra(Grafo* grafo, int origemIndex, AlgoritmoCaminhoMinimo* algCaminhoMinimo);
	};
}

#endif