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
			viewModes[currentViewMode].decHourIncrement();
			break;
		case '=':
			viewModes[currentViewMode].incHourIncrement();
			break;
		case '[':
			viewModes[currentViewMode].decPlanetRadiusScale();
			break;
		case ']':
			viewModes[currentViewMode].incPlanetRadiusScale();
			break;
		case ';':
			viewModes[currentViewMode].decStarRadiusScale();
			break;
		case '\'':
			viewModes[currentViewMode].incStarRadiusScale();
			break;
		case '.':
			viewModes[currentViewMode].decPlanetOrbitScale();
			break;
		case '/':
			viewModes[currentViewMode].incPlanetOrbitScale();
			break;
		case 'i':
			viewModes[currentViewMode].incSatelliteRadiusScale();
			break;
		case 'I':
			viewModes[currentViewMode].decSatelliteRadiusScale();
			break;
		case 'o':
			viewModes[currentViewMode].incSatelliteOrbitScale();
			break;
		case 'O':
			viewModes[currentViewMode].decSatelliteOrbitScale();
			break;
		
		case 'p':
			printf("hourIncrement: %e\n", viewModes[currentViewMode].hourIncrement);
			printf("planetRadiusScale: %e\n", viewModes[currentViewMode].planetRadiusScale);
			printf("starRadiusScale: %e\n", viewModes[currentViewMode].starRadiusScale);
			printf("satelliteRadiusScale: %e\n", viewModes[currentViewMode].satelliteRadiusScale);
			printf("orbitScale: %e\n", viewModes[currentViewMode].planetOrbitScale);
			printf("satelliteOrbitScale: %e\n", viewModes[currentViewMode].satelliteOrbitScale);
			printf("cameraDistance: %f\n", cam.distance);
			printf("eyePosition: %f, %f, %f\n", cam.getEyePos().x, cam.getEyePos().y, cam.getEyePos().z );
			break;
		
		case 27: //Esc key - exit
			exit(0);
			break;
	
		case 'z':
			currentViewMode = 0;
			cam.setView(viewModes[currentViewMode].initCameraDistance);
			break;
		case 'x':
			currentViewMode = 1;
			cam.setView(viewModes[currentViewMode].initCameraDistance);
			break;
	}
	glutPostRedisplay();
}
