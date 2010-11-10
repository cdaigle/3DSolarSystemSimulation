/**
 * planet - planet object which defines properties and methods
 *          unique to a planet - extends Sphere
 */
#include "planet.h"

#define DAYS_TO_ORBIT_SCALE 365

double Planet :: getOrbitX(double theta) {
	double x = cos(theta);
	return x*getSemiMajorAxis();
}

double Planet :: getOrbitY() {
	return 0.0;
}

double Planet :: getOrbitZ(double theta) {
	double y = sin(theta);
	return y*getSemiMinorAxis();
}

double Planet :: getSemiMajorAxis() {
	return scaleOrbit(); 
}

double Planet :: getSemiMinorAxis() {
	double secondPart = sqrt(1 - pow(eccentricity, 2));
	return getSemiMajorAxis()*secondPart;
}

//Calculates the new position of the planet, based on the circularTime
void Planet :: move() {
	double scale = (double) DAYS_TO_ORBIT_SCALE / daysToOrbit;
	double orbitPosition = scale*(daysPassed % (int) daysToOrbit);
	double theta = orbitPosition*DEG2RAD;
	setCurrentPosition(getOrbitX(theta),getOrbitY(),getOrbitZ(theta));
}

//Draws the planet, it if is enabled.  Passes in radius scale to super draw method
void Planet :: draw() {
	if( enabled == true ) {
		Sphere :: draw(planetRadiusScale);
	}
}

//Draws the circle that represents the orbit. (if the planet is enabled)
void Planet :: drawOrbit() {
	if( enabled == true && orbitEnabled == true ) {
		glPushMatrix();
			glBegin(GL_LINE_STRIP);
				for( double i = -PI; i <= PI; i+= PI/200 ) {
					glVertex3f(cos(i)*getSemiMajorAxis(),0.0,sin(i)*getSemiMinorAxis());
				}
				glVertex3f(cos(-PI)*getSemiMajorAxis(),0.0,sin(-PI)*getSemiMinorAxis()); //make sure the circle is complete
			glEnd();
		glPopMatrix();
	}
}

//Toggles whether or not the planet is enabled.  Triggered by keyboard (1-9)
void Planet :: toggle() {
	enabled = !enabled;
}

//Toggles whether or not to draw the orbit.  Triggered by 'o'.  Note: Planet must be enabled as well
void Planet :: toggleOrbit() {
	orbitEnabled = !orbitEnabled;
}
