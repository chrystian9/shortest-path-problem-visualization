#pragma once

namespace ShowCaminhoMinimo
{
	class Dijkstra
	{
	private:
		static Dijkstra* instancia_;
		Dijkstra();
	public:
		~Dijkstra();
		static Dijkstra* getInstancia();
	};
}