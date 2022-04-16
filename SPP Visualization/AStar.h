#pragma once

namespace ShowCaminhoMinimo
{
	class AStar
	{
	private:
		static AStar* instancia_;
		AStar();
	public:
		~AStar();
		static AStar* getInstancia();
	};
}