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
		delete[] stripeImage;
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
		glutInitWindowSize(800, 600);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("Show Caminho Minimo");
		init();
		glutDisplayFunc(display);
		glutReshapeFunc(reshape);
		glutKeyboardFunc(keyboardOptions);
	}

	void VisualizaCaminhoMinimo::drawArestas(Vertice* vertices, int** matrizPesos) {
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_1D);
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
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_1D);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_AUTO_NORMAL);
		glEnable(GL_NORMALIZE);
		glFrontFace(GL_CW);
		glCullFace(GL_BACK);
		glMaterialf(GL_FRONT, GL_SHININESS, 64.0);


		int quantVertices = algCaminhoMinimo_->getGrafo()->getQuantidadeVertices();

		for (int i = 0; i < quantVertices; i++) {
			Vertice verticeAux = vertices[i];
			GLfloat d1[] = { 1.0, 1.0, 1.0, 1.0 };
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, d1);

			if (!verticesPassados_[i] and i != 0) {
				GLfloat d1[] = { 0.5, 0.5, 0.5, 1.0 };
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, d1);
			}

			else {

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
#ifdef GL_VERSION_1_1
		glBindTexture(GL_TEXTURE_1D, instancia_->texName);
#endif

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

	void VisualizaCaminhoMinimo::makeStripeImage(void){
		stripeImage = new GLubyte[4 * 32];

		int j;

		for (j = 0; j < 32; j++) {
			stripeImage[4 * j] = (GLubyte)((j <= 4) ? 255 : 0);
			stripeImage[4 * j + 1] = (GLubyte)((j > 4) ? 255 : 0);
			stripeImage[4 * j + 2] = (GLubyte)0;
			stripeImage[4 * j + 3] = (GLubyte)255;
		}
	}

	void VisualizaCaminhoMinimo::init() {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		//glShadeModel(GL_FLAT);
		//glEnable(GL_DEPTH_TEST);
		//glEnable(GL_TEXTURE_2D);
		verticesPassados_[0] = true;
		glEnable(GL_DEPTH_TEST);
		makeStripeImage();
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

#ifdef GL_VERSION_1_1
		glGenTextures(1, &instancia_->texName);
		glBindTexture(GL_TEXTURE_1D, instancia_->texName);
#endif
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
#ifdef GL_VERSION_1_1
		glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, 32, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);
#else
		glTexImage1D(GL_TEXTURE_1D, 0, 4, 32, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);
#endif

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		GLfloat xequalzero[] = { 1.0, 0.0, 0.0, 0.0 };
		GLfloat* currentCoeff = xequalzero;
		GLint currentGenMode = GL_OBJECT_LINEAR;
		GLenum currentPlane = GL_OBJECT_PLANE;
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
		glTexGenfv(GL_S, currentPlane, currentCoeff);
	}

	void VisualizaCaminhoMinimo::resetProcesso() {
		if (algCaminhoMinimo_->isFim()) {
			algCaminhoMinimo_->getGrafo()->setGrafo();
			algCaminhoMinimo_->setArestasCaminhoMinimo();
			algCaminhoMinimo_->dijkstra();

			Timer(0);
		}
	}

	void VisualizaCaminhoMinimo::keyboardOptions(unsigned char key, int x, int y) {
		switch (key) {
		case 'R':
		case 'r':
			instancia_->resetProcesso();
			break;
		default:
			break;
		}
	}

	void VisualizaCaminhoMinimo::show() {
		glutTimerFunc(1000, Timer, 1);
		glutMainLoop();
	}
}