#include "transformer.h"

void world2screen(vec2& node, double width, double height) {
	node.x = (node.x + 1.) * width / 2;
	node.y = (node.y + 1.) * height / 2;
}