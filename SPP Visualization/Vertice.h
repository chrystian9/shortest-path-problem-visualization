#ifndef VERTICE_H
#define VERTICE_H

#pragma once

#include <list>
#include "Cor.h"
#include "Textura.h"
#include "Ponto.h"

namespace ShowCaminhoMinimo
{
	class Vertice
	{
	private:
		Cor cor_;
		Textura textura_;
		Ponto centro_;
	public:
		Vertice();
		Vertice(Cor cor, Textura textura, Ponto centro);
		~Vertice();
		Cor getCor();
		Textura getTextura();
		Ponto getCentro();
		void setCor(Cor cor);
		void setTextura(Textura textura);
		void setCentro(Ponto ponto);
	};
}

#endif