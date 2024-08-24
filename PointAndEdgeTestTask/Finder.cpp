#include "Finder.h"

#include <cassert>


static void Shift(Point& begin, Point& end, Point& test)
{
	test -= begin;
	end -= begin;
	begin -= begin;
}


static void Rotate(Point& end, Point& test)
{
	double length = end.length();

	// Ќаправл€щие [ко]синусы угла поворота конечной точки отрезка
	double sine = end.y / length;
	double cosine = end.x / length;

	Point toRotate = test;

	test.x = toRotate.x * cosine + toRotate.y * sine;
	test.y = -toRotate.x * sine + toRotate.y * cosine;

	toRotate = end;

	end.x = toRotate.x * cosine + toRotate.y * sine;
	end.y = -toRotate.x * sine + toRotate.y * cosine;
}



Edge FindNearestSegment(const Graph& graph, const Point& point)
{
	assert((graph.points.size() > 1) && (graph.edges.size() > 0));

	Edge edge = { -1, -1 }; // Ћучше option, но дл€ тестового задани€, которое уже не требуетс€, сойдет.
	if (!((graph.points.size() > 1) && (graph.edges.size() > 0)))
		return edge;

	double sizeX = (TOP - BOTTOM);
	double sizeY = sizeX;
	double minDistance = sqrt(sizeX * sizeX + sizeY * sizeY);

	for (const auto& testEdge : graph.edges)
	{
		Point begin = graph.points[testEdge.beginId];
		Point end = graph.points[testEdge.endId];
		Point test = point;

		Shift(begin, end, test);
		Rotate(end, test);

		double distance;
		if (test.x >= end.x)
		{
			distance = (test - end).length();
		}
		else if (test.x <= begin.x)
		{
			distance = (test - begin).length();
		}
		else
		{
			distance = fabs(test.y);
		}

		if (distance < minDistance)
		{
			minDistance = distance;
			edge = testEdge;
		}
	}

	return edge;
}