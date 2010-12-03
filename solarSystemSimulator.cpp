/**
 * Solar System Simulator.  Declares global variables and includes the necessary files.
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//Allows mouse-wheel interaction via glutMouseWheelFunc
#include <GL/freeglut_ext.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <fstream>
#include <ctime>

using namespace std;

#define PI 3.14159265
#define TWOPI 2*PI
#define DEG2RAD PI/180

#define NUM_STARS 2
#define NUM_PLANETS 9
#define NUM_RINGS 2
#define NUM_SATELLITES 2

#define NUM_VIEWMODES 3

//Global values
int static winWidth = 1000, winHeight = 650;

double static hoursPassed = -1.0;
bool static simulationRunning = false;
int static viewId = 0;

#include "supportingClasses.cpp"
#include "camera.cpp"
#include "ViewMode.cpp"
#include "RGBpixmap.h"

ViewMode views[NUM_VIEWMODES] = 
{
	ViewMode("SolarSystemView", 0.0000105, 0.0000001, 0.00000122, 0.00000001, 0.0000000177, 0.0000000001, 1000.0, 50.0, 9.93, -1, 0.0000030, 0.0000005, 0.0000005, 0.0000001),
	ViewMode("PlanetView", 0.0000105, 0.0000001, 0.00000122, 0.00000001, 0.0000000177, 0.0000000001, 2, 1.0, 9.93, 2, 0.0000030, 0.0000005, 0.0000005, 0.0000001),
	ViewMode("MoonView", 0.0000105, 0.0000001, 0.00000122, 0.00000001, 0.0000000177, 0.0000000001, 5, 1.0, 9.93, 9, 0.0000030, 0.0000005, 0.0000005, 0.0000001)
};

#include "sphere.cpp"
#include "star.cpp"
#include "planet.cpp"
#include "satellite.cpp"
#include "ring.cpp"

Planet planets[NUM_PLANETS] = 
{
	Planet("Mercury", 2400.0, 57910000.0, 0.11, 87.97, 7.0, 0.21, 0.0, 58.6, "mercurymap.bmp"),          //Mercury
	Planet("Venus", 6052.0, 108200000.0, 0.65, 224.70, 3.39, 0.01, 177.0, -243.0, "venusmap.bmp"),       //Venus
	Planet("Earth", 6378.0, 149600000.0, 0.30, 365.26, 0.0, 0.02, 23.5, 0.99, "earthmap.bmp"),           //Earth
	Planet("Mars", 3397.0, 227940000.0, 0.15, 686.98, 1.85, 0.09, 25.0, 1.03, "marsmap.bmp"),            //Mars
	Planet("Jupiter", 71492.0, 778330000.0, 0.52, 4332.71, 1.31, 0.05, 3.0, 0.41, "jupitermap.bmp"),     //Jupiter
	Planet("Saturn", 60268.0, 1429400000.0, 0.47, 10759.50, 2.49, 0.06, 27.0, 0.45, "saturnmap.bmp"),    //Saturn
	Planet("Uranus", 25559.0, 2870990000.0, 0.51, 30685.0, 0.77, 0.05, 98.0, -0.72, "uranusmap.bmp"),    //Uranus
	Planet("Neptune", 24766.0, 4504300000.0, 0.41, 60190.0, 1.77, 0.01, 30.0, 0.67, "neptunemap.bmp"),   //Neptune
	Planet("Pluto", 1150.0, 5913520000.0, 0.55, 90550.0, 17.15, 0.25, 118.0, -6.39, "plutomap.bmp" )     //Pluto
};

Ring rings[NUM_RINGS] =
{
	//Saturn's Rings - outer radius smaller than actual outer radius for aesthetic reasons
	Ring("SaturnRing", 67000.0, 139380.0, "saturnringcolor.bmp", 5, planets[5].tiltDegree),	
	//Uranus' Rings
	Ring("UranusRing", 41837.0, 51149.0, "uranusringcolor.bmp", 6, planets[6].tiltDegree)
};

Satellite satellites[NUM_SATELLITES] =
{
	Satellite("Moon", 3476.0, 384400.0, 0.1, 27.32, 5.14, 0.05, "moonmap.bmp", 2),
	// Diameter scaled from 22.2km to 3222.2km, Orbit scaled from 9378.0km to 293780.0km
	Satellite("Phobos", 3222.2, 293780.0, 0.1, 0.32, 1.00, 0.02, "phobosmap.bmp", 3)
};

Star stars[NUM_STARS] =
{
	Star("Stars", 1000/views[viewId].starRadiusScale, 0.0, 1.0, "stars.bmp"),  //Stars
	Star("Sun", 695000.0, 0.0, 1.0, "sunmap.bmp")                              //Sun
};

RGBpixmap starPixmaps[NUM_STARS];
RGBpixmap planetPixmaps[NUM_PLANETS];
RGBpixmap ringPixmaps[NUM_RINGS];
RGBpixmap satellitePixmaps[NUM_SATELLITES];

#include "init.cpp"
#include "keyboard.cpp"
#include "main.cpp"

