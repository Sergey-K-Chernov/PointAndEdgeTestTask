#include "TestCases.h"
#include <cassert>


void TestAll(std::function<Edge(Edges, Point)> func)
{
	//Test10PtsX1EdgeAlongXAxis(func);
	//Test10PtsX1EdgeAlongYAxis(func);
	Test100PtsX5EdgesZigzag(func);
}


void Test10PtsX1EdgeAlongXAxis(std::function<Edge(Edges, Point)> func)
{
	Points points = {
		{0.1, 0.0},
		{1.1, 0.0},
		{2.1, 0.0},
		{3.1, 0.0},
		{4.1, 0.0},
		{5.1, 0.0},
		{6.1, 0.0},
		{7.1, 0.0},
		{8.1, 0.0},
		{9.1, 0.0}
	};

	Edges edges = {
		{points[0], points[1]},
		{points[2], points[3]},
		{points[4], points[5]},
		{points[6], points[7]},
		{points[8], points[9]},
	};

	Point p = { 0.5, 0.0 };
	Edge result = func(edges, p);
	assert(result.begin == edges[0].begin && result.end == edges[0].end);

	p = { 0.05, 0.0 };
	result = func(edges, p);
	assert(result.begin == edges[0].begin && result.end == edges[0].end);

	p = { 1.5, 0.0 };
	result = func(edges, p);
	assert(result.begin == edges[1].begin && result.end == edges[1].end);

	p = { 9.5, 0.0 };
	result = func(edges, p);
	assert(result.begin == edges[9].begin && result.end == edges[4].end);

	p = { 10.5, 0.0 };
	result = func(edges, p);
	assert(result.begin == edges[9].begin && result.end == edges[4].end);

	p = { 4.5, 25.0 };
	result = func(edges, p);
	assert(result.begin == edges[2].begin && result.end == edges[2].end);

	p = { 0.1, 0.0 };
	result = func(edges, p);
	assert(result.begin == edges[0].begin && result.end == edges[0].end);

	p = { 1.1, 0.0 };
	result = func(edges, p);
	assert(result.begin == edges[0].begin && result.end == edges[0].end);

	p = { 1.5, 0.0 };
	result = func(edges, p);
	assert(result.begin == edges[0].begin && result.end == edges[0].end);
}


void Test10PtsX1EdgeAlongYAxis(std::function<Edge(Edges, Point)> func)
{
	Points points = {
		{0.0, 0.0},
		{0.0, 1.0},
		{0.0, 2.0},
		{0.0, 3.0},
		{0.0, 4.0},
		{0.0, 5.0},
		{0.0, 6.0},
		{0.0, 7.0},
		{0.0, 8.0},
		{0.0, 9.0}
	};

	Edges edges = {
		{points[0], points[1]},
		{points[2], points[3]},
		{points[4], points[5]},
		{points[6], points[7]},
		{points[8], points[9]},
	};

	Point p = { 0.5, 0.0 };
	auto result = func(edges, p);
	assert (result.begin == edges[0].begin && result.end == edges[0].end);
}

void Test100PtsX5EdgesZigzag(std::function<Edge(Edges, Point)> func)
{
	Points points;
	Edges edges;

	size_t upper_lower_split_id = 50;

	for (size_t i = 0; i < upper_lower_split_id; ++i)
	{
		points.push_back(Point{10 + 10.0 * i, 10.0});
	}

	for (size_t i = upper_lower_split_id; i < 100; ++i)
	{
		points.push_back(Point{10 + 10.0 * (i - upper_lower_split_id), 100.0 });
	}

	for (size_t i = 0; i < upper_lower_split_id; ++i)
	{
		for (size_t j = 0; j < 5 && (i + upper_lower_split_id + j) < points.size(); j++)
		{
			edges.push_back({ points[i], points[i + upper_lower_split_id + j] });
		}		
	}

	Point p = { 5.0, 50.0 };
	auto result = func(edges, p);
	assert(result.begin == edges[0].begin && result.end == edges[0].end);

	p = { 14.0, 38.0 };
	result = func(edges, p);
	assert(result.begin == edges[1].begin && result.end == edges[1].end);

	p = { 5.0, 105.0 };
	result = func(edges, p);
	assert(result.begin == edges[0].begin && result.end == edges[0].end);

	p = { 14.0, 105.0 };
	result = func(edges, p);
	assert(result.begin == edges[0].begin && result.end == edges[0].end);


	p = { 5.0, 6.0 };
	result = func(edges, p);
	assert(result.begin == edges[0].begin && result.end == edges[0].end || 
		result.begin == edges[1].begin && result.end == edges[1].end ||
		result.begin == edges[2].begin && result.end == edges[2].end ||
		result.begin == edges[3].begin && result.end == edges[3].end ||
		result.begin == edges[4].begin && result.end == edges[4].end
	) ;

	p = { 14.0, 6.0 };
	result = func(edges, p);
	assert(result.begin == edges[0].begin && result.end == edges[0].end ||
		result.begin == edges[1].begin && result.end == edges[1].end ||
		result.begin == edges[2].begin && result.end == edges[2].end ||
		result.begin == edges[3].begin && result.end == edges[3].end ||
		result.begin == edges[4].begin && result.end == edges[4].end
	);

	p = { 14.0, 12.0 };
	result = func(edges, p);
	assert(result.begin == edges[4].begin && result.end == edges[4].end);


	p = { 505 , 6 };
	result = func(edges, p);
	assert(result.begin == edges[239].begin && result.end == edges[239].end);

	p = { 496 , 6 };
	result = func(edges, p);
	assert(result.begin == edges[239].begin && result.end == edges[239].end);

	p = { 505 , 55 };
	result = func(edges, p);
	assert(result.begin == edges[239].begin && result.end == edges[239].end);

	p = { 505 , 105 };
	result = func(edges, p);
	assert(result.begin == edges[239].begin && result.end == edges[239].end);


	p = { 496 , 38 };
	result = func(edges, p);
	assert(result.begin == edges[238].begin && result.end == edges[238].end);

	p = { 496 , 98 };
	result = func(edges, p);
	assert(result.begin == edges[229].begin && result.end == edges[229].end);

	p = { 496 , 105 };
	result = func(edges, p);
	assert(result.begin == edges[239].begin && result.end == edges[239].end ||
		result.begin == edges[238].begin && result.end == edges[238].end ||
		result.begin == edges[236].begin && result.end == edges[236].end ||
		result.begin == edges[233].begin && result.end == edges[233].end ||
		result.begin == edges[229].begin && result.end == edges[229].end
	);


	p = { 253 , 7 };
	result = func(edges, p);
	assert(result.begin == edges[124].begin && result.end == edges[124].end ||
		result.begin == edges[125].begin && result.end == edges[125].end ||
		result.begin == edges[126].begin && result.end == edges[126].end ||
		result.begin == edges[127].begin && result.end == edges[127].end ||
		result.begin == edges[128].begin && result.end == edges[128].end
	);

	p = { 193 , 104 };
	result = func(edges, p);
	assert(result.begin == edges[73].begin && result.end == edges[73].end ||
		result.begin == edges[77].begin && result.end == edges[77].end ||
		result.begin == edges[81].begin && result.end == edges[81].end ||
		result.begin == edges[85].begin && result.end == edges[85].end ||
		result.begin == edges[89].begin && result.end == edges[89].end
	);

	p = { 205 , 92 };
	result = func(edges, p);
	assert(result.begin == edges[83].begin && result.end == edges[83].end);

	p = { 196 , 61 };
	result = func(edges, p);
	assert(result.begin == edges[90].begin && result.end == edges[90].end);
}