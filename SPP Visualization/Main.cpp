#include <iostream>
#include <gl/glut.h>
#include <list>
#include <math.h>
#include "VisualizaCaminhoMinimo.h"
using namespace std;
using namespace ShowCaminhoMinimo;

list<int>* listaAdjacencia;
Grafo* grafo;

void display(void) {
	
}

void init()
{
	/* select clearing color 	*/
	glClearColor(1.0, 1.0, 1.0, 1.0);

	/* initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
	int** matrizPesos = new int*[6];
	for (int i = 0; i < 6; i++) {
		matrizPesos[i] = new int[6];
	}

	grafo = new Grafo(matrizPesos, 6);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Show Caminho Minimo");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}