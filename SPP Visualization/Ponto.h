#pragma once

namespace ShowCaminhoMinimo
{
	class Ponto
	{
	private:
		float X_;
		float Y_;
	public:
		Ponto();
		Ponto(float X, float Y);
		Ponto(const Ponto& ponto);
		~Ponto();
		float getX();
		float getY();
		void setX(float X);
		void setY(float Y);
	};
}