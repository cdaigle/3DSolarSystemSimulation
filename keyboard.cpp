/**
 * keyboard : Handles all keyboard actions recieved from OpenGL callbacks
 */
static void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		//Camera controls
		case 'w':
			views[viewId].cam.move(views[viewId].camIncrement);
			break;
		case 's':
			views[viewId].cam.move(-views[viewId].camIncrement);
			break;
		case 'a':
			views[viewId].cam.swing(views[viewId].camIncrement);
			break;
		case 'd':
			views[viewId].cam.swing(-views[viewId].camIncrement);
			break;
		case '+':
			views[viewId].cam.zoom(-views[viewId].camIncrement);
			break;
		case '-':
			views[viewId].cam.zoom(views[viewId].camIncrement);
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
				if (planets[key-49].isEnabled())
				{
					views[viewId].lookAtId = key-49;
				}
			}
			break;
		
		case '!':
			//No Satellite
			break;
		case '@':
			//No Satellite
			break;
		case '#':
			if (satellites[0].isEnabled())
			{
				views[viewId].lookAtId = NUM_PLANETS;
			}
			break;
		case '$':
			if (satellites[1].isEnabled())
			{
				views[viewId].lookAtId = NUM_PLANETS+1;
			}
			break;
		case '%':
			//No Satellite
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
		case 'p':
			views[viewId].incSatelliteRadiusScale();
			break;
		case 'o':
			views[viewId].decSatelliteRadiusScale();
			break;
		case 'l':
			views[viewId].incSatelliteOrbitScale();
			break;
		case 'k':
			views[viewId].decSatelliteOrbitScale();
			break;
		
		case 27: //Esc key - exit
			exit(0);
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
			break;
		case GLUT_KEY_F2:
			viewId = 1;
			break;
		case GLUT_KEY_F3:
			viewId = 2;
			break;
		case GLUT_KEY_F4:
			views[viewId].reset();
			break;
			
		case GLUT_KEY_LEFT:
			views[viewId].decCamIncrement();
			break;
		case GLUT_KEY_RIGHT:
			views[viewId].incCamIncrement();
			break;
			
		case GLUT_KEY_DOWN:
			views[viewId].decScale();
			break;
		case GLUT_KEY_UP:
			views[viewId].incScale();
			break;
		
		case GLUT_KEY_PAGE_UP:
			views[viewId].incHourIncrement();
			break;
		case GLUT_KEY_PAGE_DOWN:
			views[viewId].decHourIncrement();
			break;
	}
	glutPostRedisplay();
}
