/**
 * main.cpp - main function
 */

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500

int main(int argc, char * argv[]) {
	// initialize GLUT
        glutInit( &argc, argv );		
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
		glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("3D Planet Simulation");

        // setup window callbacks
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	
	glEnable(GL_LIGHTING);  // enable the light source
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST); // for removal of hidden surfaces
	glEnable(GL_NORMALIZE);  // normalize vectors for proper shading
	
	glutIdleFunc(simulate);
	
	//Initialize the lighting, the planets and the textures
	init();				

	//Set up the viewport and initial camera
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	Point3 eye(50.0, 10.0, 0.0); 
	Point3 look(0.0, 0.0, 0.0); 
	Vector3 up(0.0, 1.0, 0.0);
	cam.set(eye, look, up); // make the initial camera
	cam.setShape(30.0f, WINDOW_WIDTH/WINDOW_HEIGHT, 0.5f, 1000.0f);

	//enter main loop
	glutMainLoop();
	return 0;
}
