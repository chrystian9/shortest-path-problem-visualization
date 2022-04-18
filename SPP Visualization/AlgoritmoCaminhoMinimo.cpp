#include "AlgoritmoCaminhoMinimo.h"

namespace ShowCaminhoMinimo
{
	AlgoritmoCaminhoMinimo::AlgoritmoCaminhoMinimo() {}

	AlgoritmoCaminhoMinimo::AlgoritmoCaminhoMinimo(int** matrizPesos, int quantidadeVertices, void (*redisplay)()) {
		dijkstraSingleton_ = Dijkstra::getInstancia();
		aStarSingleton_ = AStar::getInstancia();
		floydWarshallSingleton_ = FloydWarshall::getInstancia();

		grafo_ = new Grafo(matrizPesos, quantidadeVertices);

		redisplay_ = redisplay;

		distancias_ = new int[quantidadeVertices] {0};
	}
	
	AlgoritmoCaminhoMinimo::~AlgoritmoCaminhoMinimo() {}
	
	void AlgoritmoCaminhoMinimo::dijkstra() {
		dijkstraSingleton_->showDijkstra(grafo_, 0, this);
	}
	
	void AlgoritmoCaminhoMinimo::floydWarshall() {}
	
	void AlgoritmoCaminhoMinimo::aStar() {}

	Grafo* AlgoritmoCaminhoMinimo::getGrafo() {
		return grafo_;
	}

	int* AlgoritmoCaminhoMinimo::getDistancias() {
		return distancias_;
	}

	void AlgoritmoCaminhoMinimo::novoEvento(int distancias[]) {
		distancias_ = distancias;
		
		redisplay_();
	}
}