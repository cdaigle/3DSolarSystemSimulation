/**
 * star.cpp
 */
#include "star.h"

void Star :: draw()
{
	Sphere :: draw(views[viewId].starRadiusScale);
}

double Star :: getRadius()
{
	return Sphere :: getRadius(views[viewId].starRadiusScale);
}
