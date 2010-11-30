/**
 * keyboard : Handles all keyboard actions recieved from OpenGL callbacks
 */

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{	
	// slide controls for camera
		case 'w':
			cam.move(0.5);
			break;
		case 's':
			cam.move(-0.5);
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
			for( int i = 0; i < NUM_PLANETS; i++ )
			{
				planets[i].toggleOrbit();
			}
			break;
		
		case '!':
			//satellites[0].toggle();
			break;
		case '@':
			//satellites[1].toggle();
			break;
		case '#':
			satellites[0].toggle();
			break;
		case '$':
			//satellites[1].toggle();
			break;
		case '%':
			//satellites[2].toggle();
			break;
		case '^':
			//satellites[3].toggle();
			break;
		case '&':
			//satellites[4].toggle();
			break;
		case '*':
			//satellites[5].toggle();
			break;
		case '(':
			//satellites[6].toggle();
			break;
		case ')':
			for( int i = 0; i < NUM_SATELLITES; i++ )
			{
				satellites[i].toggleOrbit();
			}
			break;

		case '_': 
			views[viewId].decHourIncrement();
			break;
		case '=':
			views[viewId].incHourIncrement();
			break;
		case '[':
			views[viewId].decPlanetRadiusScale();
			break;
		case ']':
			views[viewId].incPlanetRadiusScale();
			break;
		case ';':
			views[viewId].decStarRadiusScale();
			break;
		case '\'':
			views[viewId].incStarRadiusScale();
			break;
		case '.':
			views[viewId].decPlanetOrbitScale();
			break;
		case '/':
			views[viewId].incPlanetOrbitScale();
			break;
		case 'i':
			views[viewId].incSatelliteRadiusScale();
			break;
		case 'I':
			views[viewId].decSatelliteRadiusScale();
			break;
		case 'o':
			views[viewId].incSatelliteOrbitScale();
			break;
		case 'O':
			views[viewId].decSatelliteOrbitScale();
			break;
		
		case 'p':
			printf("hourIncrement: %e\n", views[viewId].hourIncrement);
			printf("planetRadiusScale: %e\n", views[viewId].planetRadiusScale);
			printf("starRadiusScale: %e\n", views[viewId].starRadiusScale);
			printf("satelliteRadiusScale: %e\n", views[viewId].satelliteRadiusScale);
			printf("orbitScale: %e\n", views[viewId].planetOrbitScale);
			printf("satelliteOrbitScale: %e\n", views[viewId].satelliteOrbitScale);
			printf("cameraDistance: %f\n", cam.distance);
			printf("eyePosition: %f, %f, %f\n", cam.getEyePos().x, cam.getEyePos().y, cam.getEyePos().z );
			break;
		
		case 27: //Esc key - exit
			exit(0);
			break;
	
		case 'z':
			viewId = 0;
			printf("Changing view: SolarSystemView\n");
			cam.setView(views[viewId].initCameraDistance);
			break;
		case 'x':
			viewId = 1;
			printf("Changing view: EarthView\n");
			cam.setView(views[viewId].initCameraDistance);
			break;
		case 'c':
			viewId = 2;
			printf("Changing view: MarsView\n");
			cam.setView(views[viewId].initCameraDistance);
			break;
		case 'v':
			viewId = 3;
			printf("Changing view: JupiterView\n");
			cam.setView(views[viewId].initCameraDistance);
			break;
		case 'b':
			viewId = 4;
			printf("Changing view: SaturnView\n");
			cam.setView(views[viewId].initCameraDistance);
			break;
		case 'n':
			viewId = 5;
			printf("Changing view: UranusView\n");
			cam.setView(views[viewId].initCameraDistance);
			break;
		case 'm':
			viewId = 6;
			printf("Changing view: NeptuneView\n");
			cam.setView(views[viewId].initCameraDistance);
			break;
	}
	glutPostRedisplay();
}
