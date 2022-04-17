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

	void Grafo::setGrafo() {
		for (int i = 0; i < quantVertices_; i++) {
			for (int j = 0; j < quantVertices_; j++) {
				Cor branco(1.0, 1.0, 1.0);
				Textura textura_(1);
				Ponto origem(0.0, 0.0);
				Vertice novoVertice(branco, textura_, origem);

				vertices_[i] = novoVertice;
			}
		}
	}
}