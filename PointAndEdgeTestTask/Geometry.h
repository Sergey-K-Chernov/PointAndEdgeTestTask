#pragma once
#include <vector>

struct Point {
	double x;
	double y;
};

inline bool operator == (const Point& p1, const Point& p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

typedef std::vector<Point> Points;

struct Edge
{
	Point& begin;
	Point& end;

	Edge() = delete;
	Edge(Point& begin, Point& end) : begin(begin), end(end)
	{}

	Edge(const Edge& e) : begin(e.begin), end(e.end)
	{
	}

	Edge& operator = (const Edge& e)
	{
		begin = e.begin;
		end = e.end;
		return *this;
	}
};

typedef std::vector<Edge> Edges;