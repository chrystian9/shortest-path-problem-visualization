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

		arestasCaminhoMinimo_ = new bool*[quantidadeVertices];
		for (int i = 0; i < 6; i++) {
			arestasCaminhoMinimo_[i] = new bool[6]{ false };
		}
		
		showAlgoritmo = 0;
	}
	
	AlgoritmoCaminhoMinimo::~AlgoritmoCaminhoMinimo() {}
	
	void AlgoritmoCaminhoMinimo::dijkstra() {
		showAlgoritmo = 1;

		dijkstraSingleton_->setPropriedades(this, grafo_, 0);
	}
	
	void AlgoritmoCaminhoMinimo::floydWarshall() {}
	
	void AlgoritmoCaminhoMinimo::aStar() {}

	Grafo* AlgoritmoCaminhoMinimo::getGrafo() {
		return grafo_;
	}

	bool** AlgoritmoCaminhoMinimo::getArestasCaminhoMinimo() {
		return arestasCaminhoMinimo_;
	}

	void AlgoritmoCaminhoMinimo::novoEvento() {
		switch (showAlgoritmo)
		{
		case 1:
			arestasCaminhoMinimo_ = dijkstraSingleton_->getNovoEvento();
			break;
		default:
			break;
		}

		redisplay_();
	}
}