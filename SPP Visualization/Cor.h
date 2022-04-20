#pragma once

namespace ShowCaminhoMinimo
{
	class Cor
	{
	private:
		float R_;
		float G_;
		float B_;
		float alfa_;
	public:
		Cor();
		Cor(float R, float G, float B, float alfa);
		Cor(const Cor& cor);
		~Cor();
		float getR();
		float getG();
		float getB();
		float getAlfa();
		void setR(float R);
		void setG(float G);
		void setB(float B);
		void setAlfa(float alfa);
	};
}