#include "Grafo.h"

namespace ShowCaminhoMinimo
{
	Grafo::Grafo(int** matrizPesos, int quantidadeVertices) {
		quantVertices_ = quantidadeVertices;
		
		matrizPesos_ = new int* [quantVertices_];
		for (int i = 0; i < quantVertices_; i++) {
			matrizPesos_[i] = new int[quantVertices_]{ 0 };

			for (int j = 0; j < quantVertices_; j++) {
				matrizPesos_[i][j] = matrizPesos[i][j];
			}
		}

		vertices_ = new Vertice[quantVertices_];
		setGrafo();
	}

	Grafo::~Grafo() {
		for (int i = 0; i < 6; i++) {
			delete[] matrizPesos_[i];
		}
		delete[] matrizPesos_;
		delete[] vertices_;
	}

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
		Cor* cor;
		for (int i = 0; i < quantVertices_; i++) {
			if (i == 0) {
				cor = new Cor(1.0, 0.35, 0.0, 1.0);
			}
			else if (i == (quantVertices_ - 1)) {
				cor = new Cor(0.55, 0.75, 1.0, 1.0);
			}
			else {
				cor = new Cor(1.0, 1.0, 1.0, 1.0);
			}

			Textura textura_(1);
			float x = (float)(rand() % 8) - 3;
			float y = (float)(rand() % 8) - 3;
			Ponto ponto(x, y);
			Vertice novoVertice(*cor, textura_, ponto);
			vertices_[i] = novoVertice;
		}
	}

}