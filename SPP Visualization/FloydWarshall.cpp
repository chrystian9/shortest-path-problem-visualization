#include "FloydWarshall.h"

namespace ShowCaminhoMinimo
{
	FloydWarshall* FloydWarshall::instancia_ = nullptr;

	FloydWarshall::FloydWarshall() {}

	FloydWarshall::~FloydWarshall() {}

	FloydWarshall* FloydWarshall::getInstancia()
	{
		if (instancia_ == nullptr) {
			instancia_ = new FloydWarshall();
		}

		return instancia_;
	}
}