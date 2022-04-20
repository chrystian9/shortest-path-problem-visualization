#include "VisualizaCaminhoMinimo.h"
#include <gl/glut.h>
#include <iostream>
#include <math.h>

namespace ShowCaminhoMinimo
{
	VisualizaCaminhoMinimo* VisualizaCaminhoMinimo::instancia_ = nullptr;

	VisualizaCaminhoMinimo::VisualizaCaminhoMinimo() {}
	
	VisualizaCaminhoMinimo::~VisualizaCaminhoMinimo() {}

	VisualizaCaminhoMinimo* VisualizaCaminhoMinimo::getInstancia(int argc, char** argv, int** matrizPesos, int quantidadeVertices) {
		if (instancia_ == nullptr) {
			instancia_ = new VisualizaCaminhoMinimo();
		}

		instancia_->setPropriedades(argc, argv, matrizPesos, quantidadeVertices);

		return instancia_;
	}

	void VisualizaCaminhoMinimo::setPropriedades(int argc, char** argv, int** matrizPesos, int quantidadeVertices) {
		constroiTela(argc, argv);

		algCaminhoMinimo_ = new AlgoritmoCaminhoMinimo(matrizPesos, 6, redisplay);
		algCaminhoMinimo_->getGrafo();
		algCaminhoMinimo_->dijkstra();
	}


	void VisualizaCaminhoMinimo::dijkstra() {
		algCaminhoMinimo_->dijkstra();
	}

	void VisualizaCaminhoMinimo::floydWarshall() {
		algCaminhoMinimo_->floydWarshall();
	}
	
	void VisualizaCaminhoMinimo::aStar() {
		algCaminhoMinimo_->aStar();
	}
	
	void VisualizaCaminhoMinimo::constroiTela(int argc, char** argv) {
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(600, 600);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("Show Caminho Minimo");
		init();
		glutDisplayFunc(display);
		glutReshapeFunc(reshape);
	}

	void VisualizaCaminhoMinimo::drawArestas(Vertice* vertices, int** matrizPesos) {
		bool** aresta = algCaminhoMinimo_->getArestasCaminhoMinimo();

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

	void VisualizaCaminhoMinimo::drawVertices(Vertice* vertices) {
		for (int i = 0; i < 6; i++) {
			Vertice verticeAux = vertices[i];

			glBegin(GL_POLYGON);
			for (double i = 0; i < 2 * 3.14; i += 3.14 / 20)
				glVertex3f(verticeAux.getCentro().getX() + (cos(i) * 0.5), verticeAux.getCentro().getY() + (sin(i) * 0.5), 0.0);
			glEnd();
		}
	}

	void VisualizaCaminhoMinimo::display() {
		Vertice* vertices = instancia_->algCaminhoMinimo_->getGrafo()->getVertices();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		instancia_->drawArestas(vertices, instancia_->algCaminhoMinimo_->getGrafo()->getMatrizPesos());

		glColor3f(1.0, 1.0, 1.0);

		instancia_->drawVertices(vertices);

		glutSwapBuffers();
	}

	void VisualizaCaminhoMinimo::Timer(int value) {
		instancia_->algCaminhoMinimo_->novoEvento();
	}

	void VisualizaCaminhoMinimo::redisplay() {
		glutPostRedisplay();
		glutTimerFunc(1000, VisualizaCaminhoMinimo::Timer, 1);
	}

	void VisualizaCaminhoMinimo::reshape(int w, int h) {
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

	void VisualizaCaminhoMinimo::init() {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glShadeModel(GL_FLAT);
	}

	void VisualizaCaminhoMinimo::show() {
		glutTimerFunc(1000, Timer, 1);
		glutMainLoop();
	}
}