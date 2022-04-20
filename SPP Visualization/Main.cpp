#include <iostream>

#include "VisualizaCaminhoMinimo.h"

using namespace std;
using namespace ShowCaminhoMinimo;

int main(int argc, char** argv) {	
	int** matrizPesos = new int* [6];
	for (int i = 0; i < 6; i++) {
		matrizPesos[i] = new int[6] {0};
	}

	matrizPesos[0][1] = 2;
	matrizPesos[1][2] = 2;
	matrizPesos[1][3] = 1;
	matrizPesos[2][3] = 4;
	matrizPesos[3][4] = 3;
	matrizPesos[4][5] = 1;

	VisualizaCaminhoMinimo* visualizaCaminhoMinimoSingleton = VisualizaCaminhoMinimo::getInstancia(argc, argv, matrizPesos, 6);

	visualizaCaminhoMinimoSingleton->show();

	return 0;
}