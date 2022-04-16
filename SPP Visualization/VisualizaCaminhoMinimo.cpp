#include "VisualizaCaminhoMinimo.h"

namespace ShowCaminhoMinimo
{
	VisualizaCaminhoMinimo::VisualizaCaminhoMinimo(std::list<int> listaAdjacencia[]) {
		grafo_ = new Grafo(listaAdjacencia);
	}
	
	VisualizaCaminhoMinimo::~VisualizaCaminhoMinimo() {}
	
	void VisualizaCaminhoMinimo::constroiTela() {}

	void VisualizaCaminhoMinimo::show() {}
}