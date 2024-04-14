#pragma once
#include "geometry.h"
#include <vector>
#include "tgaimage.h"

inline vec3 computeN(const std::vector<vec3> triangle);

inline TGAColor changeColor(TGAColor color, double delta);

inline vec3 ComputeGravity(std::vector<vec3> triangle,vec3 P) {
	vec3 AB = triangle[1] - triangle[0];
	vec3 AC = triangle[2] - triangle[0];
	vec3 AP = P - triangle[0];
	vec3 X(AB.x,AC.x,AP.x);
	vec3 Y(AB.y,AC.y,AP.y);
	return cross(X, Y).normalized();
}