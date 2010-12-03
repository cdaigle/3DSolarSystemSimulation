/**
 * Main file - holds code for the main execution
 */

/**************************Display Area****************************/

static void ViewModeMenu (int value)
{
	viewId = value;
}

static void PlanetMenu (int value)
{
	switch(value)
	{
		case 1:
			for (int i = 0; i < NUM_PLANETS; i++)
			{
				planets[i].setEnabled(true);
			}
			break;
		case 2:
			for (int i = 0; i < NUM_PLANETS; i++)
			{
				planets[i].setEnabled(false);
			}
			break;
		case 3:
			for (int i = 0; i < NUM_PLANETS; i++)
			{
				planets[i].setOrbitEnabled(true);
			}
			break;
		case 4:
			for (int i = 0; i < NUM_PLANETS; i++)
			{
				planets[i].setOrbitEnabled(false);
			}
			break;
		case 5:
			for (int i = 0; i < NUM_RINGS; i++)
			{
				rings[i].setEnabled(true);
			}
			break;
		case 6:
			for (int i = 0; i < NUM_RINGS; i++)
			{
				rings[i].setEnabled(false);
			}
			break;
	}
}

static void SatelliteMenu (int value)
{
	switch(value)
	{
		case 1:
			for (int i = 0; i < NUM_SATELLITES; i++)
			{
				satellites[i].setEnabled(true);
			}
			break;
		case 2:
			for (int i = 0; i < NUM_SATELLITES; i++)
			{
				satellites[i].setEnabled(false);
			}
			break;
		case 3:
			for (int i = 0; i < NUM_SATELLITES; i++)
			{
				satellites[i].setOrbitEnabled(true);
			}
			break;
		case 4:
			for (int i = 0; i < NUM_SATELLITES; i++)
			{
				satellites[i].setOrbitEnabled(false);
			}
			break;
	}
}

static void PlanetsSubMenu (int value)
{
	if (value < 0)
	{
		rings[abs(value+1)].toggle();
	}
	else if(value < NUM_PLANETS)
	{
		planets[value].toggle();
	}
	else
	{
		planets[value-NUM_PLANETS].toggleOrbit();
	}
}

static void SatellitesSubMenu (int value)
{
	if (value < NUM_SATELLITES)
	{
		satellites[value].toggle();
	}
	else
	{
		satellites[value-NUM_SATELLITES].toggleOrbit();
	}
}

static void MainMenu(int value)
{
	switch (value)
	{
		case 1:
			simulationRunning = !simulationRunning;
			break;
		case 2:
			exit(1);
			break;
	}
}

Point3 getLookAt(int id) {
	if( id < 0 ) {
		return Point3(0.0, 0.0, 0.0); //All stars have CurrentPosition of 0.0,0.0,0.0
	} else if( id < NUM_PLANETS ) {
		return planets[id].getCurrentPosition();
	} else {
		id = id - NUM_PLANETS;
		return satellites[id].getCurrentPosition();
	}
}

void createMenu() {
	int viewModesMenu = glutCreateMenu(ViewModeMenu);
	for (int i = 0; i < NUM_VIEWMODES; i ++) 
	{
		string nameIn = views[i].getName();
		char *name = new char[strlen(nameIn.c_str())];
		strcpy(name, nameIn.c_str());
		glutAddMenuEntry(name, i);
	}
	int *planetsSubMenu = new int[NUM_PLANETS];
	for (int i = 0; i < NUM_PLANETS; i++)
	{
		planetsSubMenu[i] = glutCreateMenu(PlanetsSubMenu);
		glutAddMenuEntry("Show/Hide Planet", i);
		glutAddMenuEntry("Show/Hide Orbital Path", i+NUM_PLANETS);
		for (int j = 0; j < NUM_RINGS; j++)
		{
			if (rings[j].planetId == i)
			{
				glutAddMenuEntry("Show/Hide Ring", -(j+1));
			}
		}
	}
	int planetsMenu = glutCreateMenu(PlanetMenu);
	for (int i = 0; i < NUM_PLANETS; i++)
	{
		string nameIn = planets[i].getName();
		char *name = new char[strlen(nameIn.c_str())];
		strcpy(name, nameIn.c_str());
		glutAddSubMenu(name, planetsSubMenu[i]);
	}
	glutAddMenuEntry("Show All Planets", 1);
	glutAddMenuEntry("Hide All Planets", 2);
	glutAddMenuEntry("Show All Planets Orbital Paths", 3);
	glutAddMenuEntry("Hide All Planets Orbital Paths", 4);
	glutAddMenuEntry("Show All Rings", 5);
	glutAddMenuEntry("Hide All Rings", 6);

	int *satellitesSubMenu = new int[NUM_SATELLITES];
	for (int i = 0; i < NUM_SATELLITES; i++)
	{
		satellitesSubMenu[i] = glutCreateMenu(SatellitesSubMenu);
		glutAddMenuEntry("Show/Hide Satellite", i);
		glutAddMenuEntry("Show/Hide Orbital Path", i+NUM_SATELLITES);
	}
	int satellitesMenu = glutCreateMenu(SatelliteMenu);
	for (int i = 0; i < NUM_SATELLITES; i++)
	{
		string nameIn = satellites[i].getName();
		char *name = new char[strlen(nameIn.c_str())];
		strcpy(name, nameIn.c_str());
		glutAddSubMenu(name, satellitesSubMenu[i]);
	}
	glutAddMenuEntry("Show All Satellites", 1);
	glutAddMenuEntry("Hide All Satellites", 2);
	glutAddMenuEntry("Show All Satellites Orbital Paths", 3);
	glutAddMenuEntry("Hide All Satellites Orbital Paths", 4);

	int mainMenu = glutCreateMenu(MainMenu);
	glutAddSubMenu("View Modes", viewModesMenu);
	glutAddSubMenu("Planets",	 planetsMenu);
	glutAddSubMenu("Satellites", satellitesMenu);
	glutAddMenuEntry("Start/Stop Simulation", 1);
	glutAddMenuEntry("Quit", 2);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ViewMode view = views[viewId];
	
		view.cam.setLookAt(getLookAt(view.lookAtId));
		
		stars[0].setRadius(500 / view.starRadiusScale);
		
		//Draw the stars
		for( int i = 0; i < NUM_STARS; i++ )
		{
			stars[i].draw();
		}

		//Draw the planets
		for( int i = 0; i < NUM_PLANETS; i++ )
		{
			Planet planet = planets[i];
			planet.draw();
			planet.drawOrbit();
		}
		
		//Draw the rings
		for( int i = 0; i < NUM_RINGS; i++ ) {
			Ring ring = rings[i];
			Planet planet = planets[ring.planetId];
			if (planet.isEnabled())
			{
				glPushMatrix();
					glRotated(planet.inclination, 0, 0, 1);
					ring.draw(view.planetRadiusScale, planet.getCurrentPosition());
				glPopMatrix();
			}
		}

		//Draw the satellites
		for( int i = 0; i < NUM_SATELLITES; i++ )
		{
			Satellite sat = satellites[i];
			Planet planet = planets[sat.planetId];
			if (planet.isEnabled())
			{
				glPushMatrix();
					glRotated(planet.inclination, 0, 0, 1);
					sat.draw();
					sat.drawOrbit();
				glPopMatrix();
			}
		}

	glFlush();
	glutSwapBuffers();
}

/*********************Simulation Area************************/
//Actual function called for simulation
static void simulate()
{
	static bool init = true;
	//If enabled, move planets and increment the time
	if (simulationRunning == true || init == true)
	{
		if (init == true)
		{
			views[viewId].cam.slide(0,0,-0.001);
			init = false;
		}
		for( int i = 0; i < NUM_PLANETS; i++)
		{
			planets[i].move();
			planets[i].rotate();
		}
		for( int i = 0; i < NUM_SATELLITES; i++ )
		{
			satellites[i].move(planets[satellites[i].planetId].getCurrentPosition());
		}
		hoursPassed += views[viewId].hourIncrement; //increment the time
	}
	
	display(); //Call the display function
}

/**************************Mouse Handling****************************/
static void mouse(int x, int y)
{
	static int prevX, prevY;
	int deltaX = x - prevX, deltaY = y - prevY, tol = 3;
	
	if (abs(deltaX) > 0.0 && abs(deltaY) < tol)
	{
		if (deltaX < 0)
		{
			views[viewId].cam.swing(-views[viewId].camIncrement);
		}
		else
		{
			views[viewId].cam.swing(views[viewId].camIncrement);
		}
	}
	glutPostRedisplay();
	prevX = x;
	prevY = y;
}

void mouseWheel(int wheel, int direction, int x, int y) {
	views[viewId].cam.zoom(-direction * views[viewId].camIncrement);
	glutPostRedisplay();
}

/****************************Resize*********************************/
static void reshape(int width, int height)
{
	winWidth = width;
	winHeight = height;
	setupCameras();
}

/******************************Main********************************/
int main(int argc, char * argv[])
{
	// initialize GLUT
	glutInit( &argc, argv );		
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D Solar System Simulation");

	glutMouseWheelFunc(mouseWheel);
	glutMotionFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutSpecialFunc(keyboardSpecial);
	glutIdleFunc(simulate);
	glutReshapeFunc(reshape);
	
	createMenu();
	
	glEnable(GL_LIGHTING);   // enable the light source
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST); // for removal of hidden surfaces
	glEnable(GL_NORMALIZE);  // normalize vectors for proper shading	
	
	//Initialize the camera, lighting, the planets and the textures
	init();

	//enter main loop
	glutMainLoop();
	return 0;
}
