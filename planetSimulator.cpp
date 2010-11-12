/**
 * Planet Simulator - includes all appropriate files to run program
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

#define PI 3.14
#define DEG2RAD PI/180

//Global values
double static hoursPassedToday = -1.0;
double static hoursPassed = -1.0;
int static daysPassed = 0;

bool static simulationRunning = false;

int static currentViewMode = 0;

#include "supportingClasses.cpp"
#include "ViewMode.cpp"
#include "RGBpixmap.h"
#include "camera.cpp"
#include "init.cpp"
#include "keyboard.cpp"
#include "mouse.cpp"
#include "display.cpp"
#include "simulator.cpp"
#include "main.cpp"

