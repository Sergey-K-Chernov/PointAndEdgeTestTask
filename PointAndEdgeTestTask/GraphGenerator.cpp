#include "GraphGenerator.h"

#include <random>


Graph GenerateGraph(size_t nPoints, size_t nEdges)
{
	Graph graph;

	std::random_device rd;
	std::mt19937 random_generator(rd());
	std::uniform_real_distribution<> coordinates_distribution(BOTTOM, TOP);
	std::uniform_int_distribution<> ids_distribution(0, nPoints-1);

	auto coordinate_generator = [&coordinates_distribution, &random_generator](){
			double number;
			do {
				number = coordinates_distribution(random_generator);
			} while (number == TOP); // TOP-1 wouldn't work because the number is double
			return number;
		};

	for (size_t i = 0; i < nPoints; i++)
	{
		graph.points.push_back({ coordinate_generator(), coordinate_generator() });
	}

	for (size_t i = 0; i < nPoints; i++)
	{
		for (size_t j = 0; j < nEdges; j++)
		{
			graph.edges.push_back({static_cast<int>(i), ids_distribution(random_generator)});
		}
	}

	return graph;
}