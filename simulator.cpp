/**
 * simulator.cpp - handles the simulation callbacks for OpenGL
 */

//Allows us to increment the time when simulation is called
// allows the circular motion of the planets
void incrementTime() {
	hoursPassedToday += viewModes[currentViewMode].getHourIncrement();
	hoursPassed += viewModes[currentViewMode].getHourIncrement();
	if( hoursPassedToday >= 23.0 ) {
		daysPassed += 1;
		hoursPassedToday -= 23.0;
	}
}

//Actual function called for simulation
void simulate() {
	//Ensure we do not have to move the camera manually
	if(hoursPassedToday == -1){
		incrementTime();
		cam.slide(0,0,-0.001);
		glutPostRedisplay();
	}

	//If enabled, move planets and increment the time
	if( simulationRunning == true ) {
		for( int i = 0; i < NUM_PLANETS; i++) {
			planets[i].move();
		}
		for( int i = 0; i < NUM_SATELLITES; i++ ) {
			//satellites[i].move();
		}
		incrementTime();
	}
	
	display(); //Call the display function
}
