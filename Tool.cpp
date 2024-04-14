#include "Tool.h"

inline vec3 computeN(const std::vector<vec3> triangle) {
	return cross(triangle[2] - triangle[0], triangle[1] - triangle[0]).normalized();
}

inline TGAColor changeColor(TGAColor color, double delta) {
	for (int i = 0; i < 3; i++) {
		color[i] *= delta;
	}
	return color;
}