#include <iostream>
#include <gl/glut.h>
#include <list>
#include <math.h>

#include "VisualizaCaminhoMinimo.h"

using namespace std;
using namespace ShowCaminhoMinimo;

Grafo* grafo;
AlgoritmoCaminhoMinimo* algCaminhoMinimo;

void drawArestas(Vertice* vertices) {
	int** matrizPesos = grafo->getMatrizPesos();
	bool** aresta = algCaminhoMinimo->getArestasCaminhoMinimo();

	for (int i = 0; i < 6; i++)
	{
		Vertice Origem = vertices[i];
		for (int j = 0; j < 6; j++)
		{	
			if (matrizPesos[i][j] != 0 and aresta[i][j] == true) {
				Vertice Destino = vertices[j];
				glColor3f(1.0, 0.0, 0.0);
				glBegin(GL_LINES);
					glVertex2f(Origem.getCentro().getX(), Origem.getCentro().getY());
					glVertex2f(Destino.getCentro().getX(), Destino.getCentro().getY());
				glEnd();
			}
			else if (matrizPesos[i][j] != 0 and aresta[i][j] == false) {
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

void drawVertices(Vertice* vertices) {
	for (int i = 0; i < 6; i++) {
		Vertice verticeAux = vertices[i];

		glBegin(GL_POLYGON);
			for (double i = 0; i < 2 * 3.14; i += 3.14 / 20)
				glVertex3f(verticeAux.getCentro().getX() + (cos(i) * 0.5), verticeAux.getCentro().getY() + (sin(i) * 0.5), 0.0);
		glEnd();
	}
}

void display(void) {
	Vertice* vertices = grafo->getVertices();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	drawArestas(vertices);
	
	glColor3f(1.0, 1.0, 1.0);
	
	drawVertices(vertices);

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

void redisplay() {
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	srand(time(0));
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
		matrizPesos[i] = new int[6] {0};
	}

	matrizPesos[0][1] = 2;
	matrizPesos[1][2] = 2;
	matrizPesos[1][3] = 1;
	matrizPesos[2][3] = 4;
	matrizPesos[3][4] = 3;
	matrizPesos[4][5] = 1;
	
	algCaminhoMinimo = new AlgoritmoCaminhoMinimo(matrizPesos, 6, &redisplay);

	grafo = algCaminhoMinimo->getGrafo();

	algCaminhoMinimo->dijkstra();

	glutMainLoop();

	return 0;
}