#include "TestCases.h"
#include <cassert>


void TestAll(std::function<Edge(const Graph&, const Point&)> func)
{
	//Test10PtsX1EdgeAlongXAxis(func);
	//Test10PtsX1EdgeAlongYAxis(func);
	Test100PtsX5EdgesZigzag(func);
}


void Test10PtsX1EdgeAlongXAxis(std::function<Edge(const Graph&, const Point& p)> func)
{
	Graph graph = {
		{
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
		},
		{
			{0, 1},
			{2, 3},
			{4, 5},
			{6, 7},
			{8, 9}
		}
	};

	Point p = { 0.5, 0.0 };
	Edge result = func(graph, p);
	assert(result.beginId == graph.edges[0].beginId && result.endId == graph.edges[0].endId);

	p = { 0.05, 0.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[0].beginId && result.endId == graph.edges[0].endId);

	p = { 1.5, 0.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[1].beginId && result.endId == graph.edges[1].endId);

	p = { 9.5, 0.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[9].beginId && result.endId == graph.edges[4].endId);

	p = { 10.5, 0.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[9].beginId && result.endId == graph.edges[4].endId);

	p = { 4.5, 25.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[2].beginId && result.endId == graph.edges[2].endId);

	p = { 0.1, 0.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[0].beginId && result.endId == graph.edges[0].endId);

	p = { 1.1, 0.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[0].beginId && result.endId == graph.edges[0].endId);

	p = { 1.5, 0.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[0].beginId && result.endId == graph.edges[0].endId);
}


void Test10PtsX1EdgeAlongYAxis(std::function<Edge(const Graph&, const Point& p)> func)
{
	Graph graph = {
		{
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
		},

		{
			{0, 1},
			{2, 3},
			{4, 5},
			{6, 7},
			{8, 9}
		}
	};

	Point p = { 0.5, 0.0 };
	auto result = func(graph, p);
	assert (result.beginId == graph.edges[0].beginId && result.endId == graph.edges[0].endId);
}

void Test100PtsX5EdgesZigzag(std::function<Edge(const Graph&, const Point& p)> func)
{
	Graph graph;

	size_t upper_lower_split_id = 50;

	for (size_t i = 0; i < upper_lower_split_id; ++i)
	{
		graph.points.push_back(Point{10 + 10.0 * i, 10.0});
	}

	for (size_t i = upper_lower_split_id; i < 100; ++i)
	{
		graph.points.push_back(Point{10 + 10.0 * (i - upper_lower_split_id), 100.0 });
	}

	for (size_t i = 0; i < upper_lower_split_id; ++i)
	{
		for (size_t j = 0; j < 5 && (i + upper_lower_split_id + j) < graph.points.size(); j++)
		{
			graph.edges.push_back({ static_cast<int>(i), static_cast<int>(i + upper_lower_split_id + j) });
		}		
	}

	Point p = { 5.0, 50.0 };
	auto result = func(graph, p);
	assert(result.beginId == graph.edges[0].beginId && result.endId == graph.edges[0].endId);

	p = { 14.0, 38.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[1].beginId && result.endId == graph.edges[1].endId);

	p = { 5.0, 105.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[0].beginId && result.endId == graph.edges[0].endId);

	p = { 14.0, 105.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[0].beginId && result.endId == graph.edges[0].endId);


	p = { 5.0, 6.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[0].beginId && result.endId == graph.edges[0].endId || 
		result.beginId == graph.edges[1].beginId && result.endId == graph.edges[1].endId ||
		result.beginId == graph.edges[2].beginId && result.endId == graph.edges[2].endId ||
		result.beginId == graph.edges[3].beginId && result.endId == graph.edges[3].endId ||
		result.beginId == graph.edges[4].beginId && result.endId == graph.edges[4].endId
	) ;

	p = { 14.0, 6.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[0].beginId && result.endId == graph.edges[0].endId ||
		result.beginId == graph.edges[1].beginId && result.endId == graph.edges[1].endId ||
		result.beginId == graph.edges[2].beginId && result.endId == graph.edges[2].endId ||
		result.beginId == graph.edges[3].beginId && result.endId == graph.edges[3].endId ||
		result.beginId == graph.edges[4].beginId && result.endId == graph.edges[4].endId
	);

	p = { 14.0, 12.0 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[4].beginId && result.endId == graph.edges[4].endId);


	p = { 505 , 6 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[239].beginId && result.endId == graph.edges[239].endId);

	p = { 496 , 6 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[239].beginId && result.endId == graph.edges[239].endId);

	p = { 505 , 55 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[239].beginId && result.endId == graph.edges[239].endId);

	p = { 505 , 105 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[239].beginId && result.endId == graph.edges[239].endId);


	p = { 496 , 38 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[238].beginId && result.endId == graph.edges[238].endId);

	p = { 496 , 98 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[229].beginId && result.endId == graph.edges[229].endId);

	p = { 496 , 105 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[239].beginId && result.endId == graph.edges[239].endId ||
		result.beginId == graph.edges[238].beginId && result.endId == graph.edges[238].endId ||
		result.beginId == graph.edges[236].beginId && result.endId == graph.edges[236].endId ||
		result.beginId == graph.edges[233].beginId && result.endId == graph.edges[233].endId ||
		result.beginId == graph.edges[229].beginId && result.endId == graph.edges[229].endId
	);


	p = { 253 , 7 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[124].beginId && result.endId == graph.edges[124].endId ||
		result.beginId == graph.edges[125].beginId && result.endId == graph.edges[125].endId ||
		result.beginId == graph.edges[126].beginId && result.endId == graph.edges[126].endId ||
		result.beginId == graph.edges[127].beginId && result.endId == graph.edges[127].endId ||
		result.beginId == graph.edges[128].beginId && result.endId == graph.edges[128].endId
	);

	p = { 193 , 104 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[73].beginId && result.endId == graph.edges[73].endId ||
		result.beginId == graph.edges[77].beginId && result.endId == graph.edges[77].endId ||
		result.beginId == graph.edges[81].beginId && result.endId == graph.edges[81].endId ||
		result.beginId == graph.edges[85].beginId && result.endId == graph.edges[85].endId ||
		result.beginId == graph.edges[89].beginId && result.endId == graph.edges[89].endId
	);

	p = { 205 , 92 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[83].beginId && result.endId == graph.edges[83].endId);

	p = { 196 , 61 };
	result = func(graph, p);
	assert(result.beginId == graph.edges[90].beginId && result.endId == graph.edges[90].endId);
}