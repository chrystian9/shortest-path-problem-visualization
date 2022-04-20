#include "VisualizaCaminhoMinimo.h"
#include <gl/glut.h>
#include <iostream>
#include <math.h>

namespace ShowCaminhoMinimo
{
	VisualizaCaminhoMinimo* VisualizaCaminhoMinimo::instancia_ = nullptr;

	VisualizaCaminhoMinimo::VisualizaCaminhoMinimo() {}
	
	VisualizaCaminhoMinimo::~VisualizaCaminhoMinimo() {
		delete algCaminhoMinimo_;
		delete verticesPassados_;
	}

	VisualizaCaminhoMinimo* VisualizaCaminhoMinimo::getInstancia(int argc, char** argv, int** matrizPesos, int quantidadeVertices) {
		if (instancia_ == nullptr) {
			instancia_ = new VisualizaCaminhoMinimo();
		}

		instancia_->setPropriedades(argc, argv, matrizPesos, quantidadeVertices);

		return instancia_;
	}

	void VisualizaCaminhoMinimo::setPropriedades(int argc, char** argv, int** matrizPesos, int quantidadeVertices) {
		verticesPassados_ = new bool[quantidadeVertices] {false};

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
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);

		int quantVertices = algCaminhoMinimo_->getGrafo()->getQuantidadeVertices();
		bool** aresta = algCaminhoMinimo_->getArestasCaminhoMinimo();

		for (int i = 0; i < quantVertices; i++)
		{
			Vertice Origem = vertices[i];
			for (int j = 0; j < quantVertices; j++)
			{
				if (matrizPesos[i][j] != 0 and aresta[i][j] == true) {
					Vertice Destino = vertices[j];
					verticesPassados_[j] = true;

					glColor3f(1.0f, 0.0, 0.0f);
					glBegin(GL_LINES);
						glVertex2f(Origem.getCentro().getX(), Origem.getCentro().getY());
						glVertex2f(Destino.getCentro().getX(), Destino.getCentro().getY());
					glEnd();
				}
				else if (matrizPesos[i][j] != 0 and aresta[i][j] == false) {
					Vertice Destino = vertices[j];

					glColor3f(1.0f, 1.0f, 1.0f);
					glBegin(GL_LINES);
						glVertex2f(Origem.getCentro().getX(), Origem.getCentro().getY());
						glVertex2f(Destino.getCentro().getX(), Destino.getCentro().getY());
					glEnd();
				}
			}
		}
	}

	void VisualizaCaminhoMinimo::drawVertices(Vertice* vertices) {
		GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_shininess[] = { 50.0 };
		GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_DEPTH_TEST);

		int quantVertices = algCaminhoMinimo_->getGrafo()->getQuantidadeVertices();

		for (int i = 0; i < quantVertices; i++) {
			Vertice verticeAux = vertices[i];

			if (verticesPassados_[i] and i != 0 and i != (quantVertices-1)) {
				GLfloat d1[] = { 1.0, 0.0, 1.0, 1.0 };
				glMaterialfv(GL_FRONT, GL_DIFFUSE, d1);
			}
			else if (!verticesPassados_[i] and i != 0 and i != (quantVertices - 1)) {
				GLfloat d1[] = { 0.0, 0.0, 1.0, 1.0 };
				glMaterialfv(GL_FRONT, GL_DIFFUSE, d1);
			}
			else {
				Cor cor = verticeAux.getCor();
				
				GLfloat d1[] = { cor.getR(), cor.getG(), cor.getB(), cor.getAlfa() };
				
				glMaterialfv(GL_FRONT, GL_DIFFUSE, d1);
			}

			GLUquadric* quad;
			quad = gluNewQuadric();
			
			glPushMatrix();
			glTranslatef(verticeAux.getCentro().getX(), verticeAux.getCentro().getY(), 0);
			gluSphere(quad, 0.5, 100, 20);
			glPopMatrix();
			glEnd();
		}
	}

	void VisualizaCaminhoMinimo::display() {
		Vertice* vertices = instancia_->algCaminhoMinimo_->getGrafo()->getVertices();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		instancia_->drawArestas(vertices, instancia_->algCaminhoMinimo_->getGrafo()->getMatrizPesos());

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
		//glShadeModel(GL_FLAT);
		//glEnable(GL_DEPTH_TEST);
		//glEnable(GL_TEXTURE_2D);
		verticesPassados_[0] = true;
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_TEXTURE_2D);

	}

	void VisualizaCaminhoMinimo::show() {
		glutTimerFunc(1000, Timer, 1);
		glutMainLoop();
	}
}