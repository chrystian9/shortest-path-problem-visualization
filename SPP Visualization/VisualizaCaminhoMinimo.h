#pragma once
#include <iostream>
#include <gl/glut.h>
#include <math.h>
#include "AlgoritmoCaminhoMinimo.h"
#include "Grafo.h"

namespace ShowCaminhoMinimo
{
	class VisualizaCaminhoMinimo
	{
	private:
		static VisualizaCaminhoMinimo* instancia_;
		static void reshape(int w, int h);
		static void display(void);
		static void redisplay();
		static void keyboardOptions(unsigned char key, int x, int y);
		GLubyte* stripeImage;
#ifdef GL_VERSION_1_1
		GLuint texName;
#endif
		AlgoritmoCaminhoMinimo* algCaminhoMinimo_;
		bool* verticesPassados_;
		void constroiTela(int argc, char** argv);
		void init();
		void drawVertices(Vertice* vertices);
		void drawArestas(Vertice* vertices, int** matrizPesos);
		void setPropriedades(int argc, char** argv, int** matrizPesos, int quantidadeVertices);
		void resetProcesso();
		void makeStripeImage(void);
		VisualizaCaminhoMinimo();
	public:
		static void Timer(int value);
		static VisualizaCaminhoMinimo* getInstancia(int argc, char** argv, int** matrizPesos, int quantidadeVertices);
		~VisualizaCaminhoMinimo();
		void dijkstra();
		void floydWarshall();
		void aStar();
		void show();
	};
}