/**
 * keyboard : Handles all keyboard actions recieved from OpenGL callbacks
 */

void keyboard(unsigned char key, int x, int y) {
	switch(key)
	{	
	// slide controls for camera
		case 'w':
			//cam.slide(0,0,-0.2);
			break;
		case 's':
			//cam.slide(0,0, 0.2);
			break;
		case 'a':
			cam.swing(0.5);
			break;  // slide camera left
		case 'd':
			cam.swing(-0.5);
			break;   // slide camera right
		case '+':
			cam.zoom(-0.5);
			break;
		case '-':
			cam.zoom(0.5);
			break;
		
		//Turn simulation on/off
		case '[': 
			simulationRunning = !simulationRunning;
			break;
		
		//Toggle planets (whether they are visible or not)
		case '1': 
		case '2': 
		case '3': 
		case '4': 
		case '5': 
		case '6': 
		case '7': 
		case '8': 
		case '9': 
			planets[key-49].toggle();
			break;
		case 'o': 
			for( int i = 0; i < NUM_PLANETS; i++ ) {
				planets[i].toggleOrbit();
			}
			break;
		
		case '<': 
			viewModes[currentViewMode].decrementHourIncrement();
			break;
		case '>':
			viewModes[currentViewMode].incrementHourIncrement();
			break;
		case ';':
			viewModes[currentViewMode].decrementPlanetRadiusScale();
			break;
		case '\'':
			viewModes[currentViewMode].incrementPlanetRadiusScale();
			break;
		case ',':
			viewModes[currentViewMode].decrementOrbitScale();
			break;
		case '.':
			viewModes[currentViewMode].incrementOrbitScale();
			break;
		
		case 'p':
			printf("hourIncrement: %f\n", viewModes[currentViewMode].getHourIncrement());
			printf("planetRadiusScale: %f\n", viewModes[currentViewMode].getPlanetRadiusScale());
			printf("orbitScale: %f\n", viewModes[currentViewMode].getOrbitScale());
			break;
	}
	glutPostRedisplay(); //draw it again
}
