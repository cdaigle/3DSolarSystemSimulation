/**
 * planet - planet object which defines properties and methods
 *          unique to a planet - extends Sphere
 */
#include "planet.h"

double Planet :: getOrbitX(double theta)
{
	return cos(theta)*getSemiMajorAxis();
}

double Planet :: getOrbitY()
{
	return 0.0;
}

double Planet :: getOrbitZ(double theta)
{
	return sin(theta)*getSemiMinorAxis();
}

double Planet :: getSemiMajorAxis()
{
	return getOrbitDistance(); 
}

double Planet :: getSemiMinorAxis()
{
	return getSemiMajorAxis()*sqrt(1 - pow(eccentricity, 2));
}

//Calculates the new position of the planet, based on the circularTime
void Planet :: move()
{
	double theta = -((hoursPassed / 24) / daysToOrbit)*DEG2RAD;
	setCurrentPosition(getOrbitX(theta),getOrbitY(),getOrbitZ(theta));
}

void Planet :: rotate()
{
	orbitDegree += ((views[viewId].hourIncrement / 24) / daysToRotate)*DEG2RAD*360;
	if (orbitDegree > 360.0)
	{
		orbitDegree -= 360.0;
	}
}

//Draws the planet, it if is enabled.  Passes in radius scale to super draw method
void Planet :: draw()
{
	if( enabled == true )
	{
		glPushMatrix();
			glRotated(inclination, 0, 0, 1);
			Sphere :: draw(views[viewId].planetRadiusScale);
		glPopMatrix();
	}
}

//Draws the circle that represents the orbit. (if the planet is enabled)
void Planet :: drawOrbit()
{
	if( enabled == true && orbitEnabled == true )
	{
		glPushMatrix();
			glRotated(inclination, 0, 0, 1);
			glBegin(GL_LINE_STRIP);
				for( double i = -PI; i <= PI; i+= PI/300 )
				{
					glVertex3f(getOrbitX(i), getOrbitY(), getOrbitZ(i));
				}
				glVertex3f(getOrbitX(-PI), getOrbitY(), getOrbitZ(-PI)); //make sure the ellipse is complete
			glEnd();
		glPopMatrix();
	}
}

//Toggles whether or not the planet is enabled.  Triggered by keyboard (1-9)
void Planet :: toggle()
{
	enabled = !enabled;
}

//Toggles whether or not to draw the orbit.  Triggered by '0'.  Note: Planet must be enabled as well
void Planet :: toggleOrbit()
{
	orbitEnabled = !orbitEnabled;
}

bool Planet :: isEnabled()
{
	return enabled;
}

bool Planet :: isOrbitEnabled()
{
	return orbitEnabled;
}

void Planet :: setEnabled(bool value)
{
	enabled = value;
}

void Planet :: setOrbitEnabled(bool value)
{
	orbitEnabled = value;
}

double Planet :: getRadius()
{
	return Sphere :: getRadius(views[viewId].planetRadiusScale);
}

double Planet :: getOrbitDistance()
{
	return orbitDistance * views[viewId].planetOrbitScale;
}
