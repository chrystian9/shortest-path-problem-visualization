#ifndef ARESTA_H
#define ARESTA_H

#pragma once

#include "Vertice.h"
#include "Cor.h"

namespace ShowCaminhoMinimo
{
	class Vertice;
	class Aresta
	{
	private:
		Vertice* verticeA_;
		Vertice* verticeB_;
		Cor cor_;
		bool brilho_;
	public:
		Aresta(Vertice* verticeA, Vertice* verticeB, Cor cor, bool brilho);
		~Aresta();
		Vertice* getVerticeA();
		Vertice* getVerticeB();
		Cor getCor();
		bool isBrilho();
		void setCor(Cor cor);
	};
}

#endif