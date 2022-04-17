#pragma once

namespace ShowCaminhoMinimo
{
	class Textura
	{
	private:
		int teste_;
	public:
		Textura();
		Textura(int teste);
		Textura(const Textura& textura);
		~Textura();
	};
}