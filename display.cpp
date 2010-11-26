/**
 * display : contains code for display callback (from OpenGL)
 */

Point3 getLookAt(int id) {
	if( id < 0 ) {
		return Point3(0.0, 0.0, 0.0); //All stars have CurrentPosition of 0.0,0.0,0.0
	} else if( id < NUM_PLANETS ) {
		return planets[id].getCurrentPosition();
	} else {
		id = id - NUM_PLANETS;
		return satellites[id].getCurrentPosition();
	}
}
void display(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Draw the x, y, and z axis
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(-200.0,0.0,0.0);
			glVertex3f(200.0,0.0,0.0);
		glEnd();
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_LINE);
			glVertex3f(0.0,-200.0,0.0);
			glVertex3f(0.0,200.0,0.0);
		glEnd();
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINE);
			glVertex3f(0.0,0.0,-200.0);
			glVertex3f(0.0,0.0,200.0);
		glEnd();
		glColor3f(1.0f, 1.0f, 1.0f);
		
		//Draw the stars
		for( int i = 0; i < NUM_STARS; i++ ) {
			stars[i].draw();
		}

		//Draw the planets
		for( int i = 0; i < NUM_PLANETS; i++ ) {
			planets[i].draw();
			planets[i].drawOrbit();
		}
		
		//Draw the satellites
		for( int i = 0; i < NUM_SATELLITES; i++ ) {
			satellites[i].draw();
			satellites[i].drawOrbit();
		}

		cam.setLookAt(getLookAt(views[viewId].getId()));

	glFlush();
	glutSwapBuffers();
}
