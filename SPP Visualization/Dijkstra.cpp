#include "Dijkstra.h"

namespace ShowCaminhoMinimo
{
	Dijkstra* Dijkstra::instancia_ = nullptr;

	Dijkstra::Dijkstra() {}

	Dijkstra::~Dijkstra() {
		delete[] distancias_;
		delete[] sptSet_;
	}

	Dijkstra* Dijkstra::getInstancia()
	{
		if (instancia_ == nullptr) {
			instancia_ = new Dijkstra();
		}

		return instancia_;
	}

	void Dijkstra::setPropriedades(AlgoritmoCaminhoMinimo* algoritmoCaminhoMinimo, Grafo* grafo, int origemIndex) {
		algCaminhoMinimo_ = algoritmoCaminhoMinimo;
		grafo_ = grafo;
		origemIndex_ = origemIndex;
		quantVertices_ = grafo_->getQuantidadeVertices();
		matrizPesos_ = grafo_->getMatrizPesos();
		distancias_ = new int[quantVertices_];
		sptSet_ = new bool[quantVertices_];
		aresta_ = algCaminhoMinimo_->getArestasCaminhoMinimo();

		for (int i = 0; i < quantVertices_; i++)
			distancias_[i] = INT_MAX, sptSet_[i] = false;

		distancias_[origemIndex_] = 0;
		anterior_ = -1;

		count_ = 0;
		v_ = 0;
	}

	bool** Dijkstra::getNovoEvento() {
		while(count_ < quantVertices_ - 1) {
			int u = minDistance(distancias_, sptSet_, quantVertices_);
			sptSet_[u] = true;

			for (v_ ; v_ < quantVertices_; v_++) {
				if (!sptSet_[v_] && matrizPesos_[u][v_] && distancias_[u] != INT_MAX
					&& distancias_[u] + matrizPesos_[u][v_] < distancias_[v_]) {
					distancias_[v_] = distancias_[u] + matrizPesos_[u][v_];
					aresta_[u][v_] = true;

					count_++;
					return aresta_;
				}
			}

			anterior_ = u;
		}

		return aresta_;
	}

    int Dijkstra::minDistance(int dist[], bool sptSet[], int quantidadeVertices)
    {
        int min = INT_MAX, min_index;

        for (int v = 0; v < quantidadeVertices; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;

        return min_index;
    }
}