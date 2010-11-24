/**
 * satellite.cpp : satellite object which holds related properties and methods
 *        	        Extends sphere
 */

#include "satellite.h"

double Satellite :: getOrbitX(double theta) {
	return cos(theta) * viewModes[currentViewMode].satelliteOrbitScale;// * scaleOrbit();
}

double Satellite :: getOrbitY(double theta) {
	return 0.0;
}

double Satellite :: getOrbitZ(double theta) {
	return sin(theta) * viewModes[currentViewMode].satelliteOrbitScale;// * scaleOrbit();
}

void Satellite :: draw() {
	if( enabled == true ) {
		Sphere :: draw(viewModes[currentViewMode].satelliteRadiusScale);
	}
}

void Satellite :: drawOrbit() {
	if( enabled == true && orbitEnabled == true ) {
		glPushMatrix();
			Point3 pt = getCurrentPosition();
			glTranslated(planetPosition.x, planetPosition.y, planetPosition.z);
			glBegin(GL_LINE_STRIP);
				
				for( double i = -PI; i <= PI; i+= PI/300 ) {
					glVertex3f(getOrbitX(i), getOrbitY(i), getOrbitZ(i));
				}
				glVertex3f(getOrbitX(-PI), getOrbitY(-PI), getOrbitZ(-PI)); //make sure the ellipse is complete
			glEnd();
		glPopMatrix();
	}
}

void Satellite :: move(Planet planet) {
	double theta = ((hoursPassed / 24) / daysToOrbit)*DEG2RAD;
	planetPosition = planet.getCurrentPosition();
	setCurrentPosition(planetPosition.x+getOrbitX(theta), planetPosition.y+getOrbitY(theta), planetPosition.z+getOrbitZ(theta));
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
