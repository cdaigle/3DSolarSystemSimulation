/**
 * display : contains code for display callback (from OpenGL)
 */

Point3 getLookAt(int id) {
	if( id < 0 ) {
		id = id + NUM_STARS;
		return stars[id].getCurrentPosition();
	} else if( id < NUM_PLANETS ) {
		return planets[id].getCurrentPosition();
	} else {
		id = id - NUM_PLANETS;
		//return moons[id].getCurrentPosition();
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
		
		//Draw the mooons
//		for( int i = 0; i < NUM_MOONS; i++ ) {
//			moons[i].draw();
//		}

		cam.setLookAt(getLookAt(viewModes[currentViewMode].getId()));

	glFlush();
	glutSwapBuffers();
}
