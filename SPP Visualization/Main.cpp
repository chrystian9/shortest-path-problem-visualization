#include <iostream>
#include <gl/glut.h>
#include <list>
#include <math.h>
#include "VisualizaCaminhoMinimo.h"
using namespace std;
using namespace ShowCaminhoMinimo;

Grafo* grafo;

void drawArestas() {
	int** matrizPesos = grafo->getMatrizPesos();
	Vertice* vertices = grafo->getVertices();

	for (int i = 0; i < 6; i++)
	{
		Vertice Origem = vertices[i];
		for (int j = 0; j < 6; j++)
		{	
			if (matrizPesos[i][j] != NULL) {
				Vertice Destino = vertices[j];
				glColor3f(1.0, 1.0, 1.0);
				glBegin(GL_LINES);
				glVertex2f(Origem.getCentro().getX(), Origem.getCentro().getY());
				glVertex2f(Destino.getCentro().getX(), Destino.getCentro().getY());
				glEnd();
			}
		}
	}
}

void drawVertices() {
	Vertice* vertices = grafo->getVertices();

	for (int i = 0; i < 6; i++) {
		Vertice verticeAux = vertices[i];

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		for (double i = 0; i < 2 * 3.14; i += 3.14 / 20)
			glVertex3f(verticeAux.getCentro().getX() + (cos(i) * 0.5), verticeAux.getCentro().getY() + (sin(i) * 0.5), 0.0);
		glEnd();
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	drawArestas();
	drawVertices();
	
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-5.0, 5.0, -5.0 * (GLfloat)h / (GLfloat)w,
			5.0 * (GLfloat)h / (GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0 * (GLfloat)w / (GLfloat)h,
			5.0 * (GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Show Caminho Minimo");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
	int** matrizPesos = new int* [6];
	for (int i = 0; i < 6; i++) {
		matrizPesos[i] = new int[6];
	}

	matrizPesos[0][1] = 2;
	matrizPesos[1][2] = 2;
	matrizPesos[1][3] = 1;
	matrizPesos[2][3] = 4;
	matrizPesos[3][4] = 3;
	matrizPesos[4][5] = 1;
	grafo = new Grafo(matrizPesos, 6);
	
	glutMainLoop();

	return 0;
}