#ifndef VERTICE_H
#define VERTICE_H

#pragma once

#include "VerticeAresta.h"
#include "Cor.h"
#include "Textura.h"
#include "Ponto.h"

namespace ShowCaminhoMinimo
{
	class Aresta;
	class VerticeAresta;
	class Vertice
	{
	private:
		VerticeAresta* vizinhos_;
		Cor cor_;
		Textura textura_;
		Ponto centro_;
	public:
		Vertice(VerticeAresta* vizinhos, Cor cor, Textura textura, Ponto centro);
		~Vertice();
		VerticeAresta* getVizinhos();
		Cor getCor();
		Textura getTextura();
		Ponto getCentro();
		void setVizinhos(VerticeAresta* vizinhos);
		void setCor(Cor cor);
		void setTextura(Textura textura);
		void setCentro(Ponto ponto);
	};
}

#endif