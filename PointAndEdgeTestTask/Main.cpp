#include <iostream>
#include <fstream>
#include "Geometry.h"
#include "TestCases.h"
#include "GraphGenerator.h"
#include "Finder.h"


void printGraphForMatplotlib(const Graph& graph, std::ostream& out)
{
	for (auto& edge : graph.edges)
	{
		double x1, x2, y1, y2;
		
		x1 = graph.points[edge.beginId].x;
		x2 = graph.points[edge.endId].x;

		y1 = graph.points[edge.beginId].y;
		y2 = graph.points[edge.endId].y;

		out << "ax.plot([" << x1 << ", " << x2 << "], "
			<< "[" << y1 << ", " << y2 << "], label=\""
			<< edge.beginId << "-" << edge.endId << "\")\n";
	}
}


void printGraphForTestCase(const Graph& graph, std::ostream& out)
{
	out << "\tGraph graph = {\n\t\t{\n";
	for (auto& point : graph.points)
	{
		out << "\t\t\t{" << point.x << ", " << point.y << "},\n";
	}
	out << "\t\t},\n\t\t{\n";
	for (auto& edge : graph.edges)
	{
		out << "\t\t\t{" << edge.beginId << ", " << edge.endId << "},\n";

	}
	out << "\t\t},\n\t}\n";
}


int main()
{
	//TestAll(FindNearestSegment);
	auto graph = GenerateGraph(100, 5);

	std::ofstream tc("tc.txt");
	std::ofstream mpl("mpl.txt");

	printGraphForTestCase(graph, tc);
	printGraphForMatplotlib(graph, mpl);
	return 0;
}