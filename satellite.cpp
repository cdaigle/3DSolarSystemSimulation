/**
 * satellite.cpp : satellite object which holds related properties and methods
 *        	        Extends sphere
 */

#include "satellite.h"

double Satellite :: getOrbitX(double theta) {
	return cos(theta) * viewModes[currentViewMode].getSatelliteOrbitScale();// * scaleOrbit();
}

double Satellite :: getOrbitY(double theta) {
	return 0.0;
}

double Satellite :: getOrbitZ(double theta) {
	return sin(theta) * viewModes[currentViewMode].getSatelliteOrbitScale();// * scaleOrbit();
}

void Satellite :: draw() {
	if( enabled == true ) {
		Sphere :: draw(viewModes[currentViewMode].getSatelliteRadiusScale());
	}
}

void Satellite :: drawOrbit() {
	if( enabled == true && orbitEnabled == true ) {
		glPushMatrix();
			glBegin(GL_LINE_STRIP);
				Point3 pt = getCurrentPosition();
				for( double i = -PI; i <= PI; i+= PI/300 ) {
					glVertex3f(pt.x+getOrbitX(i), pt.y+getOrbitY(i), pt.z+getOrbitZ(i));
				}
				glVertex3f(pt.x+getOrbitX(-PI), pt.y+getOrbitY(-PI), pt.z+getOrbitZ(-PI)); //make sure the ellipse is complete
			glEnd();
		glPopMatrix();
	}
}

void Satellite :: move(Planet planet) {
	double theta = ((hoursPassed / 24) / daysToOrbit)*DEG2RAD;
	Point3 pt = planet.getCurrentPosition();
	setCurrentPosition(pt.x+getOrbitX(theta), pt.y+getOrbitY(theta), pt.z+getOrbitZ(theta));
}

int Satellite :: getPlanetId() {
	return planetId;
}

void Satellite :: toggle() {
	enabled = !enabled;
}

void Satellite :: toggleOrbit() {
	orbitEnabled = !orbitEnabled;
}
