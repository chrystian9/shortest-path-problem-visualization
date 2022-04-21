#ifndef VERTICE_H
#define VERTICE_H

#pragma once

#include <list>
#include "Cor.h"
#include "Ponto.h"

namespace ShowCaminhoMinimo
{
	class Vertice
	{
	private:
		Cor cor_;
		Ponto centro_;
	public:
		Vertice();
		Vertice(Cor cor, Ponto centro);
		~Vertice();
		Cor getCor();
		Ponto getCentro();
		void setCor(Cor cor);
		void setCentro(Ponto ponto);
	};
}

#endif