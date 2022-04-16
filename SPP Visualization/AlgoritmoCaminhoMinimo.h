#pragma once
#include "Dijkstra.h"
#include "FloydWarshall.h"
#include "AStar.h"

namespace ShowCaminhoMinimo
{
	class AlgoritmoCaminhoMinimo
	{
	private:
		Dijkstra* dijkstraSingleton_;
		FloydWarshall* floydWarshallSingleton_;
		AStar* aStarSingleton_;
	public:
		AlgoritmoCaminhoMinimo();
		~AlgoritmoCaminhoMinimo();
		void dijkstra();
		void floydWarshall();
		void aStar();
		//Evento novoEvento();
	};
}