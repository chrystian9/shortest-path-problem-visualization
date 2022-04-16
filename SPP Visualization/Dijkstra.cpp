#include "Dijkstra.h"

namespace ShowCaminhoMinimo
{
	Dijkstra* Dijkstra::instancia_ = nullptr;

	Dijkstra::Dijkstra() {}

	Dijkstra::~Dijkstra() {}

	Dijkstra* Dijkstra::getInstancia()
	{
		if (instancia_ == nullptr) {
			instancia_ = new Dijkstra();
		}

		return instancia_;
	}
}