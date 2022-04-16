#pragma once

namespace ShowCaminhoMinimo
{
	class Cor
	{
	private:
		float R_;
		float G_;
		float B_;
	public:
		Cor();
		Cor(float R, float G, float B);
		Cor(const Cor& cor);
		~Cor();
		float getR();
		float getG();
		float getB();
		void setR(float R);
		void setG(float G);
		void setB(float B);
	};
}