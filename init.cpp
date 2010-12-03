/**
 * Init : contains init code for solar system simulation
 */

void setupLighting(void) {
	GLfloat light0_position[] = {0.0f, 0.0f, 0.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	// set the light source properties
	GLfloat light_ambient[] = {0.9, 0.9, 0.9, 1.0f};
	GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0f};
	GLfloat light_specular[] = {0.7, 0.7, 0.7, 1.0f};

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

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

	for( int i = 0; i < NUM_RINGS; i++ ) {
		rings[i].textureId = 4000 + i;
		int value = ringPixmaps[i].readBMPFile(rings[i].getTexturePath());
		ringPixmaps[i].setTexture(rings[i].textureId);
	}
	
	for( int i = 0; i < NUM_SATELLITES; i++ ) {
		satellites[i].textureId = 3001 + NUM_PLANETS + i;
		int value = satellitePixmaps[i].readBMPFile(satellites[i].getTexturePath());
		satellitePixmaps[i].setTexture(satellites[i].textureId);
	}
}

void setupCameras(void) {
	//Set up the viewport and initial camera's (for each view mode)
	glViewport(0, 0, winWidth, winHeight);
	for (int i = 0; i < NUM_VIEWMODES; i++)
	{
		views[i].setupCam();
	}
}

void init(void) {
	setupLighting();
	setupTextures();
	setupCameras();
}
