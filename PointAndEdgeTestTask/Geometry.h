#pragma once
#include <vector>

const double BOTTOM = 0;
const double TOP = 1000;

struct Point {
	double x;
	double y;

	double lengthSq() { return x * x + y * y; }
	double length() { return sqrt(lengthSq()); }

	Point& operator -= (const Point& p)
	{
		x -= p.x;
		y -= p.y;
		return *this;
	}
};

inline Point operator - (const Point& p1, const Point& p2)
{
	return { p1.x - p2.x, p1.y - p2.y };
}


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