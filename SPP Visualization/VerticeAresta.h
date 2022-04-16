
#ifndef VERTICEARESTA_H
#define VERTICEARESTA_H

#pragma once

#include "Vertice.h"
#include "Aresta.h"

namespace ShowCaminhoMinimo
{
	class Vertice;
	class Aresta;
	class VerticeAresta
	{
	private:
		Vertice* vertice_;
		Aresta* aresta_;
	public:
		VerticeAresta(Vertice* vertice, Aresta* aresta);
		~VerticeAresta();
		Vertice* getVertice();
		Aresta* getAresta();
		void setVertice(Vertice* vertice);
		void setAresta(Aresta* aresta);
	};
}

#endif