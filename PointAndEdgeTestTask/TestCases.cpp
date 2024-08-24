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


void Test100PtsX5EdgesFromRandom(std::function<Edge(const Graph&, const Point&)> func)
{
	Graph graph = {
		{
			{249.873, 948.267},
			{334.39, 522.456},
			{161.239, 117.606},
			{758.414, 114.805},
			{410.909, 108.058},
			{703.596, 332.384},
			{558.463, 264.677},
			{160.349, 821.529},
			{192.684, 710.538},
			{582.085, 238.366},
			{133.383, 361.322},
			{104.525, 37.0188},
			{66.9626, 617.869},
			{683.627, 715.062},
			{358.139, 179.588},
			{220.527, 916.736},
			{103.788, 695.671},
			{624.732, 19.6551},
			{192.808, 216.874},
			{433.933, 656.532},
			{48.2756, 506.702},
			{336.693, 147.049},
			{809.013, 291.273},
			{262.087, 328.041},
			{721.482, 835.535},
			{522.287, 785.372},
			{580.84, 9.30195},
			{176.979, 970.323},
			{748.179, 142.308},
			{910.83, 801.276},
			{955.431, 778.419},
			{512.637, 478.316},
			{981.204, 422.265},
			{754.227, 569.776},
			{757.371, 97.5876},
			{921.487, 612.078},
			{570.107, 324.626},
			{73.3459, 600.942},
			{234.035, 487.154},
			{69.5885, 598.909},
			{304.464, 448.332},
			{949.147, 592.025},
			{256.141, 946.31},
			{469.296, 980.029},
			{448.69, 736.192},
			{147.392, 87.7254},
			{107.293, 106.003},
			{799.612, 563.15},
			{460.711, 159.347},
			{502.078, 353.184},
			{761.217, 596.263},
			{759.198, 663.622},
			{574.233, 162.326},
			{21.4503, 821.871},
			{188.42, 959.906},
			{602.897, 730.371},
			{419.005, 782.536},
			{136.939, 26.4592},
			{227.002, 628.852},
			{851.377, 808.029},
			{903.245, 42.6964},
			{722.749, 693.195},
			{306.126, 97.3759},
			{622.101, 745.71},
			{343.136, 285.692},
			{175.379, 77.01},
			{327.349, 39.9046},
			{584.858, 588.382},
			{333.131, 43.9963},
			{496.58, 687.168},
			{728.548, 810.188},
			{292.611, 212.897},
			{18.0087, 766.111},
			{408.286, 870.111},
			{364.342, 473.939},
			{890.895, 198.778},
			{142.015, 419.99},
			{823.601, 795.661},
			{488.355, 282.641},
			{136.328, 72.1013},
			{502.074, 865.055},
			{646.53, 471.352},
			{928.816, 861.091},
			{435.502, 704.887},
			{376.96, 613.891},
			{656.787, 607.202},
			{55.7682, 715.489},
			{269.584, 977.717},
			{590.77, 95.3119},
			{64.4881, 180.661},
			{396.967, 418.1},
			{80.8231, 759.786},
			{853.738, 753.811},
			{420.984, 753.318},
			{992.967, 146.017},
			{339.256, 362.534},
			{469.831, 519.94},
			{346.581, 169.621},
			{961.595, 178.606},
			{877.448, 72.2962},
		},
		{
			{0, 84},
			{0, 19},
			{0, 19},
			{0, 81},
			{0, 83},
			{1, 38},
			{1, 7},
			{1, 31},
			{1, 96},
			{1, 54},
			{2, 20},
			{2, 27},
			{2, 42},
			{2, 54},
			{2, 95},
			{3, 95},
			{3, 21},
			{3, 21},
			{3, 27},
			{3, 69},
			{4, 53},
			{4, 53},
			{4, 18},
			{4, 5},
			{4, 14},
			{5, 47},
			{5, 73},
			{5, 71},
			{5, 34},
			{5, 0},
			{6, 50},
			{6, 36},
			{6, 64},
			{6, 94},
			{6, 40},
			{7, 94},
			{7, 49},
			{7, 85},
			{7, 67},
			{7, 97},
			{8, 3},
			{8, 90},
			{8, 72},
			{8, 47},
			{8, 81},
			{9, 97},
			{9, 3},
			{9, 74},
			{9, 42},
			{9, 9},
			{10, 29},
			{10, 60},
			{10, 68},
			{10, 32},
			{10, 70},
			{11, 23},
			{11, 76},
			{11, 8},
			{11, 41},
			{11, 47},
			{12, 26},
			{12, 51},
			{12, 82},
			{12, 3},
			{12, 45},
			{13, 62},
			{13, 55},
			{13, 2},
			{13, 5},
			{13, 25},
			{14, 91},
			{14, 11},
			{14, 50},
			{14, 70},
			{14, 48},
			{15, 47},
			{15, 30},
			{15, 99},
			{15, 7},
			{15, 6},
			{16, 6},
			{16, 54},
			{16, 88},
			{16, 72},
			{16, 71},
			{17, 18},
			{17, 82},
			{17, 74},
			{17, 81},
			{17, 12},
			{18, 52},
			{18, 84},
			{18, 48},
			{18, 60},
			{18, 38},
			{19, 37},
			{19, 14},
			{19, 95},
			{19, 97},
			{19, 88},
			{20, 74},
			{20, 30},
			{20, 89},
			{20, 15},
			{20, 11},
			{21, 99},
			{21, 44},
			{21, 37},
			{21, 36},
			{21, 24},
			{22, 32},
			{22, 20},
			{22, 39},
			{22, 40},
			{22, 77},
			{23, 70},
			{23, 87},
			{23, 96},
			{23, 46},
			{23, 35},
			{24, 67},
			{24, 59},
			{24, 8},
			{24, 56},
			{24, 66},
			{25, 10},
			{25, 7},
			{25, 59},
			{25, 26},
			{25, 48},
			{26, 78},
			{26, 74},
			{26, 84},
			{26, 36},
			{26, 10},
			{27, 81},
			{27, 84},
			{27, 65},
			{27, 6},
			{27, 51},
			{28, 10},
			{28, 76},
			{28, 14},
			{28, 17},
			{28, 87},
			{29, 99},
			{29, 1},
			{29, 48},
			{29, 1},
			{29, 16},
			{30, 51},
			{30, 2},
			{30, 40},
			{30, 49},
			{30, 74},
			{31, 95},
			{31, 23},
			{31, 85},
			{31, 14},
			{31, 7},
			{32, 91},
			{32, 60},
			{32, 52},
			{32, 53},
			{32, 74},
			{33, 38},
			{33, 55},
			{33, 40},
			{33, 76},
			{33, 63},
			{34, 37},
			{34, 69},
			{34, 40},
			{34, 22},
			{34, 4},
			{35, 20},
			{35, 41},
			{35, 67},
			{35, 66},
			{35, 59},
			{36, 74},
			{36, 84},
			{36, 83},
			{36, 95},
			{36, 98},
			{37, 53},
			{37, 88},
			{37, 36},
			{37, 72},
			{37, 78},
			{38, 5},
			{38, 36},
			{38, 38},
			{38, 57},
			{38, 31},
			{39, 49},
			{39, 64},
			{39, 48},
			{39, 43},
			{39, 38},
			{40, 11},
			{40, 48},
			{40, 28},
			{40, 13},
			{40, 83},
			{41, 6},
			{41, 53},
			{41, 12},
			{41, 78},
			{41, 3},
			{42, 55},
			{42, 19},
			{42, 92},
			{42, 59},
			{42, 55},
			{43, 11},
			{43, 96},
			{43, 3},
			{43, 80},
			{43, 0},
			{44, 25},
			{44, 53},
			{44, 51},
			{44, 11},
			{44, 61},
			{45, 4},
			{45, 59},
			{45, 68},
			{45, 44},
			{45, 62},
			{46, 35},
			{46, 76},
			{46, 24},
			{46, 13},
			{46, 56},
			{47, 1},
			{47, 77},
			{47, 93},
			{47, 66},
			{47, 17},
			{48, 45},
			{48, 79},
			{48, 94},
			{48, 95},
			{48, 13},
			{49, 23},
			{49, 51},
			{49, 9},
			{49, 12},
			{49, 48},
			{50, 37},
			{50, 60},
			{50, 58},
			{50, 57},
			{50, 11},
			{51, 77},
			{51, 21},
			{51, 52},
			{51, 84},
			{51, 17},
			{52, 69},
			{52, 78},
			{52, 96},
			{52, 69},
			{52, 47},
			{53, 74},
			{53, 10},
			{53, 17},
			{53, 31},
			{53, 93},
			{54, 51},
			{54, 92},
			{54, 31},
			{54, 76},
			{54, 68},
			{55, 33},
			{55, 87},
			{55, 88},
			{55, 40},
			{55, 84},
			{56, 54},
			{56, 86},
			{56, 83},
			{56, 18},
			{56, 58},
			{57, 65},
			{57, 26},
			{57, 79},
			{57, 69},
			{57, 60},
			{58, 79},
			{58, 34},
			{58, 6},
			{58, 71},
			{58, 59},
			{59, 69},
			{59, 48},
			{59, 66},
			{59, 29},
			{59, 78},
			{60, 55},
			{60, 20},
			{60, 16},
			{60, 35},
			{60, 62},
			{61, 65},
			{61, 58},
			{61, 82},
			{61, 73},
			{61, 83},
			{62, 45},
			{62, 96},
			{62, 47},
			{62, 56},
			{62, 73},
			{63, 78},
			{63, 68},
			{63, 89},
			{63, 41},
			{63, 46},
			{64, 95},
			{64, 76},
			{64, 41},
			{64, 44},
			{64, 92},
			{65, 48},
			{65, 6},
			{65, 64},
			{65, 49},
			{65, 16},
			{66, 28},
			{66, 52},
			{66, 31},
			{66, 92},
			{66, 9},
			{67, 2},
			{67, 30},
			{67, 89},
			{67, 51},
			{67, 34},
			{68, 46},
			{68, 15},
			{68, 79},
			{68, 0},
			{68, 34},
			{69, 49},
			{69, 64},
			{69, 96},
			{69, 24},
			{69, 35},
			{70, 86},
			{70, 89},
			{70, 70},
			{70, 51},
			{70, 42},
			{71, 87},
			{71, 19},
			{71, 10},
			{71, 38},
			{71, 97},
			{72, 77},
			{72, 64},
			{72, 12},
			{72, 35},
			{72, 3},
			{73, 95},
			{73, 44},
			{73, 26},
			{73, 77},
			{73, 68},
			{74, 18},
			{74, 66},
			{74, 29},
			{74, 99},
			{74, 22},
			{75, 40},
			{75, 38},
			{75, 82},
			{75, 44},
			{75, 28},
			{76, 57},
			{76, 42},
			{76, 20},
			{76, 85},
			{76, 71},
			{77, 87},
			{77, 17},
			{77, 20},
			{77, 15},
			{77, 4},
			{78, 97},
			{78, 6},
			{78, 85},
			{78, 45},
			{78, 5},
			{79, 3},
			{79, 37},
			{79, 60},
			{79, 11},
			{79, 48},
			{80, 80},
			{80, 24},
			{80, 12},
			{80, 74},
			{80, 56},
			{81, 96},
			{81, 73},
			{81, 77},
			{81, 11},
			{81, 62},
			{82, 68},
			{82, 65},
			{82, 4},
			{82, 65},
			{82, 12},
			{83, 2},
			{83, 41},
			{83, 3},
			{83, 8},
			{83, 49},
			{84, 87},
			{84, 64},
			{84, 53},
			{84, 28},
			{84, 97},
			{85, 92},
			{85, 57},
			{85, 64},
			{85, 14},
			{85, 9},
			{86, 50},
			{86, 99},
			{86, 43},
			{86, 22},
			{86, 13},
			{87, 79},
			{87, 50},
			{87, 23},
			{87, 65},
			{87, 20},
			{88, 69},
			{88, 10},
			{88, 91},
			{88, 12},
			{88, 61},
			{89, 63},
			{89, 76},
			{89, 88},
			{89, 5},
			{89, 79},
			{90, 51},
			{90, 13},
			{90, 4},
			{90, 24},
			{90, 34},
			{91, 63},
			{91, 26},
			{91, 26},
			{91, 65},
			{91, 37},
			{92, 92},
			{92, 41},
			{92, 26},
			{92, 13},
			{92, 19},
			{93, 47},
			{93, 60},
			{93, 89},
			{93, 59},
			{93, 81},
			{94, 83},
			{94, 49},
			{94, 8},
			{94, 36},
			{94, 74},
			{95, 32},
			{95, 81},
			{95, 48},
			{95, 35},
			{95, 8},
			{96, 23},
			{96, 65},
			{96, 15},
			{96, 55},
			{96, 33},
			{97, 64},
			{97, 44},
			{97, 74},
			{97, 51},
			{97, 22},
			{98, 59},
			{98, 5},
			{98, 78},
			{98, 12},
			{98, 91},
			{99, 83},
			{99, 88},
			{99, 47},
			{99, 5},
			{99, 78},
		},
	};

	Points points = {
		{50, 300},
		{10, 300},
		{400, 25},
		{130, 810},
		{140, 820},
		{999, 390},
		{387, 541},
		{633, 457},
		{247, 609},
		{601.5, 655}
	};

	Edges edges = {
		{20, 89},
		{20, 89},
		{57, 60},
		{53, 93},
		{16, 54},
		{32, 60},
		{80, 74},
		{81, 62},
		{58, 34},
		{55, 88}
	};

	assert(points.size() == edges.size());

	for (size_t i = 0; i < points.size(); i++)
	{
		auto result = func(graph, points[i]);
		assert(result.beginId == edges[i].beginId && result.endId == edges[i].endId);
	}
}