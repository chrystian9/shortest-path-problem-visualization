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

		setArestasCaminhoMinimo();
		
		showAlgoritmo = 0;
	}
	
	AlgoritmoCaminhoMinimo::~AlgoritmoCaminhoMinimo() {
		delete dijkstraSingleton_;
		delete aStarSingleton_;
		delete floydWarshallSingleton_;
		delete grafo_;
		destroyArestasCaminhoMinimo();
	}
	
	void AlgoritmoCaminhoMinimo::dijkstra() {
		showAlgoritmo = 1;

		dijkstraSingleton_->setPropriedades(this, grafo_, 0);
	}
	
	void AlgoritmoCaminhoMinimo::floydWarshall() {}
	
	void AlgoritmoCaminhoMinimo::aStar() {}

	Grafo* AlgoritmoCaminhoMinimo::getGrafo() {
		return grafo_;
	}

	void AlgoritmoCaminhoMinimo::setArestasCaminhoMinimo() {
		if(arestasCaminhoMinimo_ != nullptr){
			destroyArestasCaminhoMinimo();
		}
		
		int quantidadeVertices = grafo_->getQuantidadeVertices();

		arestasCaminhoMinimo_ = new bool* [quantidadeVertices];
		for (int i = 0; i < quantidadeVertices; i++) {
			arestasCaminhoMinimo_[i] = new bool[quantidadeVertices]{ false };
		}
	}

	bool** AlgoritmoCaminhoMinimo::getArestasCaminhoMinimo() {
		return arestasCaminhoMinimo_;
	}

	void AlgoritmoCaminhoMinimo::destroyArestasCaminhoMinimo() {
		for (int i = 0; i < 6; i++) {
			delete[] arestasCaminhoMinimo_[i];
		}
		delete[] arestasCaminhoMinimo_;
	}

	bool AlgoritmoCaminhoMinimo::isFim() {
		switch (showAlgoritmo)
		{
		case 1:
			return dijkstraSingleton_->isFim();
			break;
		default:
			break;
		}
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