#include "Dijkstra.h"

namespace ShowCaminhoMinimo
{
	Dijkstra* Dijkstra::instancia_ = nullptr;

	Dijkstra::Dijkstra() {}

	Dijkstra::~Dijkstra() {}

	Dijkstra* Dijkstra::getInstancia()
	{
		if (instancia_ == nullptr) {
			instancia_ = new Dijkstra();
		}

		return instancia_;
	}

	void Dijkstra::showDijkstra(Grafo* grafo, int origemIndex, AlgoritmoCaminhoMinimo* algCaminhoMinimo) {
		int quantVertices = grafo->getQuantidadeVertices();
		int** matrizPesos = grafo->getMatrizPesos();
		int* distancias = new int[quantVertices];
		bool* sptSet = new bool[quantVertices];
		bool** aresta = algCaminhoMinimo->getArestasCaminhoMinimo();

		for (int i = 0; i < quantVertices; i++)
			distancias[i] = INT_MAX, sptSet[i] = false;

		distancias[origemIndex] = 0;
		Vertice* listaV = grafo->getVertices();
		int anterior = -1;

		for (int count = 0; count < quantVertices - 1; count++) {
			int u = minDistance(distancias, sptSet, quantVertices);
			sptSet[u] = true;

			for (int v = 0; v < quantVertices; v++) {
				if (!sptSet[v] && matrizPesos[u][v] && distancias[u] != INT_MAX
					&& distancias[u] + matrizPesos[u][v] < distancias[v]) {
					distancias[v] = distancias[u] + matrizPesos[u][v];
					aresta[u][v] = true;

					algCaminhoMinimo->novoEvento(aresta);
				}
			}

			anterior = u;
		}
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