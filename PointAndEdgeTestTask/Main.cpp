#include <iostream>
#include <fstream>
#include "Geometry.h"
#include "TestCases.h"
#include "GraphGenerator.h"
#include "Finder.h"
#include "Utils.h"


std::pair<Point, Point> task(size_t nPoints, size_t nEdges, Point point)
{
	auto graph = GenerateGraph(100, 5);

	/*
	std::ofstream tc("tc.txt");
	std::ofstream mpl("mpl.txt");

	printGraphForTestCase(graph, tc);
	printGraphForMatplotlib(graph, mpl);
	//*/

	auto edge = FindNearestSegment(graph, point);

	return {graph.points[edge.beginId], graph.points[edge.endId]};
}


int main()
{
	//TestAll(FindNearestSegment);	

	auto result = task(77, 4, {456, 654});

	std::cout << "{" << result.first.x << ", " << result.first.y << "}, {"
			  << result.second.x << ", " << result.second.y << "}\n";

	return 0;
}