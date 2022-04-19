#ifndef ALGORITMO_CAMINHO_MINIMO_H
#define ALGORITMO_CAMINHO_MINIMO_H
#pragma once

#include "Dijkstra.h"
#include "FloydWarshall.h"
#include "AStar.h"
#include "Grafo.h"

namespace ShowCaminhoMinimo
{
	class Dijkstra;
	class Grafo;
	class AlgoritmoCaminhoMinimo
	{
	private:
		Dijkstra* dijkstraSingleton_;
		FloydWarshall* floydWarshallSingleton_;
		AStar* aStarSingleton_;
		Grafo* grafo_;
		void (*redisplay_)();
		bool** arestasCaminhoMinimo_;
	public:
		AlgoritmoCaminhoMinimo();
		AlgoritmoCaminhoMinimo(int** matrizPesos, int quantidadeVertices, void (*display)());
		~AlgoritmoCaminhoMinimo();
		void dijkstra();
		void floydWarshall();
		void aStar();
		Grafo* getGrafo();
		bool** getArestasCaminhoMinimo();
		void novoEvento(bool** arestasCaminhoMinimo);
	};
}

#endif