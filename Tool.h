#pragma once
#include "geometry.h"
#include <vector>
#include "tgaimage.h"
#include "transformer.h"

inline vec3 computeN(const std::vector<vec3> triangle) {
	return cross(triangle[2] - triangle[0], triangle[1] - triangle[0]).normalized();
}

inline TGAColor changeColor(TGAColor color, double delta) {
	for (int i = 0; i < 3; i++) {
		color[i] *= delta;
	}
	return color;
}

inline vec3 ComputeGravity(std::vector<vec3> triangle, vec3 P) {
	vec3 AB = triangle[1] - triangle[0];
	vec3 AC = triangle[2] - triangle[0];
	vec3 X = { AB.x, AC.x,  triangle[0].x - P.x };
	vec3 Y = { AB.y, AC.y,  triangle[0].y - P.y };
	vec3 ret = cross(X, Y).normalized();
	if (ret.z < 1e-8 && ret.z > -1e-8) {
		ret = { -1,1,1 };
		return ret;
	}
	ret = ret / ret.z;
	ret = { 1 - ret.x - ret.y, ret.x, ret.y };
	return ret;
}

inline bool IsInSide(vec3 massCenter) {
	return (massCenter.x > 0 && massCenter.y > 0 && massCenter.z > 0);
}

// l r t b
inline std::vector<double> generateBox(const std::vector<vec3> triangle,vec2 screenSize) {
	std::vector<double> ret;
	double temp = std::min(triangle[0].x, triangle[1].x);
	temp = std::min(triangle[2].x, temp);
	ret.push_back(temp);
	temp = std::max(triangle[0].x, triangle[1].x);
	temp = std::max(triangle[2].x, temp);
	ret.push_back(temp);
	temp = std::max(triangle[0].y, triangle[1].y);
	temp = std::max(triangle[2].y, temp);
	ret.push_back(temp);
	temp = std::min(triangle[0].y, triangle[1].y);
	temp = std::min(triangle[2].y, temp);
	ret.push_back(temp);
	return ret;
}

inline vec<4> addDim(vec3 v) {
	vec<4> ret = { v.x,v.y,v.z, 1};
	return ret;
}

inline vec3 reduceDim(vec<4> v) {
	vec3 ret = { v[0],v[1], v[2] };
	return ret;
}

inline mat<4, 4> ViewMat(int width, int height, int depth) {
	mat<4,4> ret = mat<4, 4>::identity();
	//第4列表示平移信息
	ret[0][3] = width / 2.f;
	ret[1][3] = height / 2.f;
	ret[2][3] = depth / 2.f;
	//对角线表示缩放信息
	ret[0][0] = width / 2.f;
	ret[1][1] = height / 2.f;
	ret[2][2] = depth / 2.f;
	return ret;
}