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
		AlgoritmoCaminhoMinimo* algCaminhoMinimo_;
		Grafo* grafo_;
		int quantVertices_;
		int** matrizPesos_;
		int* distancias_;
		bool* sptSet_;
		bool** aresta_;
		int anterior_;
		int origemIndex_;
		int count_;
		int v_;
		Dijkstra();
		static int minDistance(int dist[], bool sptSet[], int quantidadeVertices);
	public:
		~Dijkstra();
		static Dijkstra* getInstancia();
		bool** getNovoEvento();
		void setPropriedades(AlgoritmoCaminhoMinimo* algoritmoCaminhoMinimo, Grafo* grafo, int origemIndex);
		bool isFim();
	};
}

#endif