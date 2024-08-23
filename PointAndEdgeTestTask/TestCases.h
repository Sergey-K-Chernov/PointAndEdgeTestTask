#pragma once
#include <vector>
#include <functional>

#include "Geometry.h"

void TestAll(std::function<Edge(const Graph&, const Point&)> func);

void Test10PtsX1EdgeAlongXAxis(std::function<Edge(const Graph&, const Point&)> func);
void Test10PtsX1EdgeAlongYAxis(std::function<Edge(const Graph&, const Point&)> func);
void Test100PtsX5EdgesZigzag(std::function<Edge(const Graph&, const Point&)> func);