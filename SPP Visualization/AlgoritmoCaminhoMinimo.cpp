#include "AlgoritmoCaminhoMinimo.h"
#include "Dijkstra.h"
#include "AStar.h"
#include "FloydWarshall.h"

namespace ShowCaminhoMinimo
{
	AlgoritmoCaminhoMinimo::AlgoritmoCaminhoMinimo() {
		dijkstraSingleton_ = Dijkstra::getInstancia();
		aStarSingleton_ = AStar::getInstancia();
		floydWarshallSingleton_ = FloydWarshall::getInstancia();
	}
	
	AlgoritmoCaminhoMinimo::~AlgoritmoCaminhoMinimo() {}
	
	void AlgoritmoCaminhoMinimo::dijkstra() {}
	
	void AlgoritmoCaminhoMinimo::floydWarshall() {}
	
	void AlgoritmoCaminhoMinimo::aStar() {}
}