#include "Grafo.h"

namespace ShowCaminhoMinimo
{
	Grafo::Grafo(int** matrizPesos, int quantidadeVertices) {
		quantVertices_ = quantidadeVertices;
		matrizPesos_ = matrizPesos;
		vertices_ = new Vertice[quantVertices_];
		setGrafo();
	}

	Grafo::~Grafo() {}

	Vertice* Grafo::getVertices() {
		return vertices_;
	}

	int** Grafo::getMatrizPesos() {
		return matrizPesos_;
	}

	int Grafo::getQuantidadeVertices() {
		return quantVertices_;
	}

	void Grafo::setGrafo() {
		for (int i = 0; i < quantVertices_; i++) {
			Cor branco(1.0, 1.0, 1.0);
			Textura textura_(1);
			float x = (float)(rand() % 10) - 5;
			float y = (float)(rand() % 10) - 5;
			Ponto origem(x, y);
			Vertice novoVertice(branco, textura_, origem);
			vertices_[i] = novoVertice;
		}
	}
	


}