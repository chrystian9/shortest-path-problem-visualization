#pragma once

namespace ShowCaminhoMinimo
{
	class FloydWarshall
	{
	private:
		static FloydWarshall* instancia_;
		FloydWarshall();
	public:
		~FloydWarshall();
		static FloydWarshall* getInstancia();
	};
}