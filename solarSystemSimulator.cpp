/**
 * Planet Simulator - includes all appropriate files to run program
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//Allows mouse-wheel interaction via glutMouseWheelFunc
#include <GL/freeglut_ext.h>
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

#define PI 3.14
#define DEG2RAD PI/180
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500

#define NUM_STARS 2
#define NUM_PLANETS 9
#define NUM_SATELLITES 1

#define NUM_VIEWMODES 2

//Global values
double static hoursPassedToday = -1.0;
double static hoursPassed = -1.0;
int static daysPassed = 0;

bool static simulationRunning = false;

int static viewId = 0;

#include "supportingClasses.cpp"
#include "ViewMode.cpp"
#include "RGBpixmap.h"
#include "camera.cpp"

ViewMode views[NUM_VIEWMODES] = {
	ViewMode("SolarSystemView", 0.0000105, 0.0000001, 0.00000122, 0.00000001, 0.0000000177, 0.0000000001, 1000.0, 50.0, 9.93, -1, 0.0000030, 0.0000001, 0.1067, 0.0001),
	ViewMode("EarthView", 0.0000105, 0.0000001, 0.00000122, 0.00000001, 0.0000000177, 0.0000000001, 1000.0, 50.0, 9.93, 2, 0.0000030, 0.0000001, 0.1067, 0.0001)
};

Camera cam(views[viewId].initCameraDistance);

#include "sphere.cpp"
#include "star.cpp"
#include "planet.cpp"
#include "satellite.cpp"

Planet planets[NUM_PLANETS] = {
	Planet("Mercury", 2400.0, 57910000.0, 0.11, 87.97, 7.0, 0.21, "mercurymap.bmp"),            //Mercury
	Planet("Venus", 6052.0, 108200000.0, 0.65, 224.70, 3.39, 0.01, "venusmap.bmp"),             //Venus
	Planet("Earth", 6378.0, 149600000.0, 0.30, 365.26, 0.0, 0.02, "earthmap.bmp"),              //Earth
	Planet("Mars", 3397.0, 227940000.0, 0.15, 686.98, 1.85, 0.09, "marsmap.bmp"),               //Mars
	Planet("Jupiter", 71492.0, 778330000.0, 0.52, 4332.71, 1.31, 0.05, "jupitermap.bmp"),       //Jupiter
	Planet("Saturn", 60268.0, 1429400000.0, 0.47, 10759.50, 2.49, 0.06, "saturnmap.bmp"),       //Saturn
	Planet("Uranus", 25559.0, 2870990000.0, 0.51, 30685.0, 0.77, 0.05, "uranusmap.bmp"),        //Uranus
	Planet("Neptune", 24766.0, 4504300000.0, 0.41, 60190.0, 1.77, 0.01, "neptunemap.bmp"),      //Neptune
	Planet("Pluto", 1150.0, 5913520000.0, 0.55, 90550.0, 17.15, 0.25, "plutomap.bmp" )          //Pluto
};

Satellite satellites[NUM_SATELLITES] = {
	Satellite("Moon", 3476, 384400.0, 1.0, 27.32, 5.14, 0.05, "moonmap.bmp", 2)                 //Earth's Moon
};

Star stars[NUM_STARS] = {
	Star("Stars", 125/views[viewId].starRadiusScale, 0.0, 1.0, "stars.bmp"),
	Star("Sun", 695000.0, 0.0, 1.0, "sunmap.bmp")                                               //Sun
};

RGBpixmap starPixmaps[NUM_STARS];
RGBpixmap planetPixmaps[NUM_PLANETS];
RGBpixmap satellitePixmaps[NUM_SATELLITES];

#include "init.cpp"
#include "keyboard.cpp"
#include "mouse.cpp"
#include "display.cpp"
#include "simulator.cpp"
#include "main.cpp"

