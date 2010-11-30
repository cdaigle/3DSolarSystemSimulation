/**
 * satellite.cpp : satellite object which holds related properties and methods
 *        	        Extends sphere
 */

#include "satellite.h"

double Satellite :: getOrbitX(double theta)
{
	return cos(theta) * views[viewId].satelliteOrbitScale;
}

double Satellite :: getOrbitY(double theta)
{
	return 0.0;
}

double Satellite :: getOrbitZ(double theta)
{
	return sin(theta) * views[viewId].satelliteOrbitScale;
}

void Satellite :: draw()
{
	if( enabled == true ) {
		glPushMatrix();
			//glRotated(inclination, 1, 0, 0);
			Sphere :: draw(views[viewId].satelliteRadiusScale);
		glPopMatrix();
	}
}

void Satellite :: drawOrbit()
{
	if( enabled == true && orbitEnabled == true )
	{
		glPushMatrix();
			//glRotated(inclination, 1, 0, 0);
			glPushMatrix();
				Point3 pt = getCurrentPosition();
				glTranslated(planetPosition.x, planetPosition.y, planetPosition.z);
				glBegin(GL_LINE_STRIP);
					for( double i = -PI; i <= PI; i+= PI/300 )
					{
						glVertex3f(getOrbitX(i), getOrbitY(i), getOrbitZ(i));
					}
					glVertex3f(getOrbitX(-PI), getOrbitY(-PI), getOrbitZ(-PI)); //make sure the ellipse is complete
				glEnd();
			glPopMatrix();
		glPopMatrix();
	}
}

void Satellite :: move(Planet planet)
{
	double theta = ((hoursPassed / 24) / daysToOrbit)*DEG2RAD;
	planetPosition = planet.getCurrentPosition();
	setCurrentPosition(planetPosition.x+getOrbitX(theta), planetPosition.y+getOrbitY(theta), planetPosition.z+getOrbitZ(theta));
}

void Satellite :: toggle()
{
	enabled = !enabled;
}

void Satellite :: toggleOrbit()
{
	orbitEnabled = !orbitEnabled;
}

bool Satellite :: isEnabled()
{
	return enabled;
}

bool Satellite :: isOrbitEnabled()
{
	return orbitEnabled;
}

void Satellite :: setEnabled(bool value)
{
	enabled = value;
}

void Satellite :: setOrbitEnabled(bool value)
{
	orbitEnabled = value;
}

double Satellite :: getRadius()
{
	return Sphere :: getRadius(views[viewId].satelliteRadiusScale);
}
