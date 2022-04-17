#include "Textura.h"

namespace ShowCaminhoMinimo
{
	Textura::Textura() {}

	Textura::Textura(int teste) {
		teste_ = teste;
	}

	Textura::Textura(const Textura& textura) {
		teste_ = textura.teste_;
	}

	Textura::~Textura(){}
}