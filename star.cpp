/**
 * star.cpp
 */
#include "star.h"

void Star :: draw() {
	Sphere :: draw(views[viewId].starRadiusScale);
}
