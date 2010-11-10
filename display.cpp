/**
 * display : contains code for display callback (from OpenGL)
 */

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
		
		//Draw the Sun
		Sun.draw();
		//Draw the planets (and moons)
		for( int i = 0; i < NUM_PLANETS; i++ ) {
			planets[i].draw();
			planets[i].drawOrbit();
		}
	
	glFlush();
	glutSwapBuffers();
}
