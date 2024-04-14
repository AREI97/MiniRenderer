#include "Triangle.h"
#include <algorithm>

struct {
	bool operator()(vec2 a, vec2 b) const {
		return a.y < b.y;
	}
} cmp;

void Triangle(std::vector<vec2>& veters, TGAColor color, TGAImage& image) {
	sort(veters.begin(),veters.end(), cmp);
	double step = 0.01;
	for (double y = veters.front().y; y < veters.back().y; ) {
		while (y < veters[1].y) {
			double x1 = (y - veters[0].y) * (veters[2].x - veters[0].x) / (veters[2].y - veters[0].y) + veters[0].x;
			double x2 = (y - veters[0].y) * (veters[1].x - veters[0].x) / (veters[1].y - veters[0].y) + veters[0].x;
			Line(x1, y, x2, y, color, image);
			y += step;
		}
		while (y < veters.back().y && y >= veters[1].y) {
			double x1 = (y - veters[0].y) * (veters[2].x - veters[0].x) / (veters[2].y - veters[0].y) + veters[0].x;
			double x2 = (y - veters[1].y) * (veters[2].x - veters[1].x) / (veters[2].y - veters[1].y) + veters[1].x;
			Line(x1, y, x2, y, color, image);
			y += step;
		}
	}
}