/**
 * Init : contains init code for planet simulation
 */

void setupLighting(void) {
	GLfloat light0_position[] = {0.0f, 0.0f, 0.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	// set the light source properties (white)
	GLfloat lightWhite_ambient[] = {0.5, 0.5, 0.5, 1.0f};
	GLfloat lightWhite_diffuse[] = {0.9, 0.9, 0.7, 1.0f};
	GLfloat lightWhite_specular[] = {1.0, 1.0, 1.0, 1.0f};

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightWhite_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightWhite_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightWhite_specular);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void setupTextures(void) {
	// Initialize textures
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	for( int i = 0; i < NUM_STARS; i++ ) {
		stars[i].textureId = 3000 - i;
		int value = starPixmaps[i].readBMPFile(stars[i].getTexturePath());
		starPixmaps[i].setTexture(stars[i].textureId);
	}

	for( int i = 0; i < NUM_PLANETS; i++ ) {
		planets[i].textureId = 3001 + i;
		int value = planetPixmaps[i].readBMPFile(planets[i].getTexturePath());
		planetPixmaps[i].setTexture(planets[i].textureId);
	}
	
	for( int i = 0; i < NUM_SATELLITES; i++ ) {
		satellites[i].textureId = 3001 + NUM_PLANETS + i;
		int value = satellitePixmaps[i].readBMPFile(satellites[i].getTexturePath());
		satellitePixmaps[i].setTexture(satellites[i].textureId);
	}
}

void setupCamera(void) {
	//Set up the viewport and initial camera
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	Point3 eye = views[viewId].initEyePos;
	Point3 look = views[viewId].initLookPos;
	Vector3 up(0.0, 1.0, 0.0);
	cam.set(eye, look, up);
	cam.setShape(30.0f, WINDOW_WIDTH/WINDOW_HEIGHT, 0.5f, 250.0f);
}

void init(void) {
	setupLighting();
	setupTextures();
	setupCamera();
}
