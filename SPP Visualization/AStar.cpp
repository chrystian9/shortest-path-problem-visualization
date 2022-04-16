#include "AStar.h"

namespace ShowCaminhoMinimo
{
	AStar* AStar::instancia_ = nullptr;

	AStar::AStar() {}

	AStar::~AStar() {}

	AStar* AStar::getInstancia()
	{
		if (instancia_ == nullptr) {
			instancia_ = new AStar();
		}

		return instancia_;
	}
}