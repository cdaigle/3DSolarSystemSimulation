/**
 * keyboard : Handles all keyboard actions recieved from OpenGL callbacks
 */

void keyboard(unsigned char key, int x, int y) {
	switch(key)
	{	
	// slide controls for camera
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
		case 32:   //Space key 
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
		case '0': 
			for( int i = 0; i < NUM_PLANETS; i++ ) {
				planets[i].toggleOrbit();
			}
			break;
		
		case '!':
			satellites[0].toggle();
			break;
		case '@':
			satellites[1].toggle();
			break;
		case '#':
			satellites[2].toggle();
			break;
		case '$':
			satellites[3].toggle();
			break;
		case '%':
			satellites[4].toggle();
			break;
		case '^':
			satellites[5].toggle();
			break;
		case '&':
			satellites[6].toggle();
			break;
		case '*':
			satellites[7].toggle();
			break;
		case '(':
			satellites[8].toggle();
			break;
		case ')':
			for( int i = 0; i < NUM_SATELLITES; i++ ) {
				satellites[i].toggleOrbit();
			}
			break;

		case '_': 
			viewModes[currentViewMode].decrementHourIncrement();
			break;
		case '=':
			viewModes[currentViewMode].incrementHourIncrement();
			break;
		case '[':
			viewModes[currentViewMode].decrementPlanetRadiusScale();
			break;
		case ']':
			viewModes[currentViewMode].incrementPlanetRadiusScale();
			break;
		case ';':
			viewModes[currentViewMode].decrementStarRadiusScale();
			break;
		case '\'':
			viewModes[currentViewMode].incrementStarRadiusScale();
			break;
		case '.':
			viewModes[currentViewMode].decrementOrbitScale();
			break;
		case '/':
			viewModes[currentViewMode].incrementOrbitScale();
			break;
		case 'i':
			viewModes[currentViewMode].incrementSatelliteRadiusScale();
			break;
		case 'I':
			viewModes[currentViewMode].decrementSatelliteRadiusScale();
			break;
		case 'o':
			viewModes[currentViewMode].incrementSatelliteOrbitScale();
			break;
		case 'O':
			viewModes[currentViewMode].decrementSatelliteOrbitScale();
			break;
		
		case 'p':
			printf("hourIncrement: %e\n", viewModes[currentViewMode].getHourIncrement());
			printf("planetRadiusScale: %e\n", viewModes[currentViewMode].getPlanetRadiusScale());
			printf("starRadiusScale: %e\n", viewModes[currentViewMode].getStarRadiusScale());
			printf("satelliteRadiusScale: %e\n", viewModes[currentViewMode].getSatelliteRadiusScale());
			printf("orbitScale: %e\n", viewModes[currentViewMode].getOrbitScale());
			printf("satelliteOrbitScale: %e\n", viewModes[currentViewMode].getSatelliteOrbitScale());
			printf("cameraDistance: %f\n", cam.getCameraDistance());
			printf("eyePosition: %f, %f, %f\n", cam.getEyePosition().x, cam.getEyePosition().y, cam.getEyePosition().z );
			break;
		
		case 27: //Esc key - exit
			exit(0);
			break;
	
		case GLUT_KEY_F1:
			currentViewMode = 0;
			cam.setView(viewModes[currentViewMode].getInitialCameraDistance());
			break;
		case GLUT_KEY_F2:
			currentViewMode = 1;
			cam.setView(viewModes[currentViewMode].getInitialCameraDistance());
			break;
	}
	glutPostRedisplay(); //draw it again
}
