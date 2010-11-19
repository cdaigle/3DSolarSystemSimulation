/**
 * main.cpp - main function
 */

int main(int argc, char * argv[]) {
	// initialize GLUT
	glutInit( &argc, argv );		
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D Planet Simulation");

	glutMotionFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	
	glEnable(GL_LIGHTING);   // enable the light source
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST); // for removal of hidden surfaces
	glEnable(GL_NORMALIZE);  // normalize vectors for proper shading
	
	glutIdleFunc(simulate);
	
	//Initialize the camera, lighting, the planets and the textures
	init();

	//enter main loop
	glutMainLoop();
	return 0;
}
