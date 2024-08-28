#pragma once
#include <iostream>

struct Graph;

void printGraphForMatplotlib(const Graph& graph, std::ostream& out);
void printGraphForTestCase(const Graph& graph, std::ostream& out);