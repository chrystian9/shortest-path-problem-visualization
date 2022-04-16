#include "VisualizaCaminhoMinimo.h"
#include <gl/glut.h>
#include <iostream>
#include <math.h>

namespace ShowCaminhoMinimo
{
	VisualizaCaminhoMinimo::VisualizaCaminhoMinimo(std::list<int> listaAdjacencia[]) {
		grafo_ = new Grafo(listaAdjacencia);
	}
	
	VisualizaCaminhoMinimo::~VisualizaCaminhoMinimo() {}
	void VisualizaCaminhoMinimo::init()
	{
		/* select clearing color 	*/
		glClearColor(1.0, 1.0, 1.0, 1.0);

		/* initialize viewing values  */
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	}
	void VisualizaCaminhoMinimo::constroiTela() {
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(600, 600);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("Banheiro");
		init();
		glutDisplayFunc(display);
		glutMainLoop();
	}

	void VisualizaCaminhoMinimo::show() {
		constroiTela();
	}
}

void display() {}