#include "transformer.h"

vec3 world2screen(vec3 node, double width, double height) {
	node.x = (node.x + 1.) * width / 2;
	node.y = (node.y + 1.) * height / 2;
	vec3 ret = { node.x,node.y,node.z };
	return ret;
}

vec3 screen2world(vec3 node, double width, double height) {
	node.x = (node.x * 2) / width - 1.;
	node.y = (node.y * 2) / height - 1.;
	vec3 ret = { node.x,node.y, node.z };
	return ret;
}


