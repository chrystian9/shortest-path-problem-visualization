#include <iostream>
#include <list>
#include "VisualizaCaminhoMinimo.h"
using namespace std;
using namespace ShowCaminhoMinimo;

int main() {
	list<int> listaAdjacencia[2];
	VisualizaCaminhoMinimo showCaminhoMinimo(listaAdjacencia);

	showCaminhoMinimo.show();

	return 0;
}