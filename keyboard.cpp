/**
 * keyboard : Handles all keyboard actions recieved from OpenGL callbacks
 */
static void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		//Camera controls
		case 'w':
			cam.move(0.5);
			break;
		case 's':
			cam.move(-0.5);
			break;
		case 'a':
			cam.swing(0.5);
			break;
		case 'd':
			cam.swing(-0.5);
			break;
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
		
		//Set place to look at.  1-9 are the planets, !-( are the satellites, 0 is the sun.
		case '0':
		case '1': 
		case '2': 
		case '3': 
		case '4': 
		case '5': 
		case '6': 
		case '7': 
		case '8': 
		case '9': 
			if (key == 0)
			{
				views[viewId].lookAtId = -1;
			}
			else
			{
				views[viewId].lookAtId = key-49;
			}
			break;
		
		case '!':
			//No Satellite
			break;
		case '@':
			//No Satellite
			break;
		case '#':
			views[viewId].lookAtId = NUM_PLANETS;
			break;
		case '$':
			views[viewId].lookAtId = NUM_PLANETS+1;
			break;
		case '%':
			views[viewId].lookAtId = NUM_PLANETS+2;
			break;
		case '^':
			//No Satellite
			break;
		case '&':
			//No Satellite
			break;
		case '*':
			//No Satellite
			break;
		case '(':
			//No Satellite
			break;
		
		//Toggle orbital paths
		case '`': 
			for( int i = 0; i < NUM_PLANETS; i++ )
			{
				planets[i].toggleOrbit();
			}
			break;
		case '~':
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
		
		case 'l':
			glEnable(GL_LIGHTING);
			break;
		case 'L':
			glDisable(GL_LIGHTING);
			break;
		case 'k':
			glEnable(GL_LIGHT0);
			break;
		case 'K':
			glDisable(GL_LIGHT0);
			break;
		case 'j':
			glEnable(GL_NORMALIZE);
			break;
		case 'J':
			glDisable(GL_NORMALIZE);
			break;
	}
	glutPostRedisplay();
}

static void keyboardSpecial(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_F1:
			viewId = 0;
			cam.setView(views[viewId].initCameraDistance);
			break;
		case GLUT_KEY_F2:
			viewId = 1;
			cam.setView(views[viewId].initCameraDistance);
			break;
		case GLUT_KEY_F3:
			viewId = 2;
			cam.setView(views[viewId].initCameraDistance);
			break;
		case GLUT_KEY_LEFT:
			keyboard('a', 0, 0);
			break;			
		case GLUT_KEY_RIGHT:
			keyboard('d', 0, 0);
			break;			
		case GLUT_KEY_DOWN:
			keyboard('s', 0, 0);
			break;
		case GLUT_KEY_UP:
			keyboard('w', 0, 0);
			break;
	}
}
