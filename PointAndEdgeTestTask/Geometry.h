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
	int beginId;
	int endId;
};

typedef std::vector<Edge> Edges;

struct Graph
{
	Points points;
	Edges edges;
};