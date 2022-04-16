#pragma once
#include <list>
#include "AlgoritmoCaminhoMinimo.h"
#include "Grafo.h"

namespace ShowCaminhoMinimo
{
	class VisualizaCaminhoMinimo
	{
	private: 
		AlgoritmoCaminhoMinimo algCaminhoMinimo_;
		Grafo* grafo_;
		void constroiTela();
		void display();
	public:
		VisualizaCaminhoMinimo(std::list<int> listaAdjacencia[]);
		~VisualizaCaminhoMinimo();
		void show();
	};
}