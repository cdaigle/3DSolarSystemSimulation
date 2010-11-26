/**
 * main.cpp - main function
 */

void mouse(int x, int y)
{
	static int prevX, prevY;
	int deltaX = x - prevX, deltaY = y - prevY, tol = 3;
	
	if( abs(deltaX) > 0.0 && abs(deltaY) < tol ) {
		cam.swing(deltaX);
	}
	
	glutPostRedisplay();
	prevX = x;
	prevY = y;
}

void mouseWheel(int wheel, int direction, int x, int y) {
	cam.zoom(-direction/2.0);
	glutPostRedisplay();
}

int main(int argc, char * argv[])
{
	// initialize GLUT
	glutInit( &argc, argv );		
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D Solar System Simulation");

	glutMouseWheelFunc(mouseWheel);
	glutMotionFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutIdleFunc(simulate);

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
