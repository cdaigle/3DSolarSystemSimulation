/**
 * star.cpp
 */
#include "star.h"

void Star :: draw() {
	Sphere :: draw(viewModes[currentViewMode].getStarRadiusScale());
}
