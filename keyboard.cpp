/**
 * keyboard : Handles all keyboard actions recieved from OpenGL callbacks
 */

void keyboard(unsigned char key, int x, int y) {
	switch(key)
	{	
	// slide controls for camera
		case 'w': 
			cam.slide(0,0,-0.2); 
			break;    // slide camera forward
		case 's': 
			cam.slide(0,0, 0.2);
			break;    // slide camera back	
		case 'a': 
			cam.slide(-0.2, 0, 0);
			break;  // slide camera left
		case 'd': 
			cam.slide(0.2, 0, 0);
			break;   // slide camera right
		case '+':
			cam.slide(0, 0.2, 0);
			break;   // slide camera up
		case '-': 
			cam.slide(0, -0.2, 0);
			break;  // slide camera down
	
	// angular motion of the camera
		case 'Q': 
			cam.roll(-1);
			break;  // roll camera left
		case 'E':
			cam.roll(1);
			break;  // roll camera right
		case 'A':
			cam.yaw(1);
			break;  // yaw camera left
		case 'D':
			cam.yaw(-1);
			break;  // yaw camera right
		case 'S':
			cam.pitch(-1);
			break;  // pitch camera down
		case 'W':
			cam.pitch(1);
			break;  // pitch camera up

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
