/**
 * mouse : handles all mouse actions
 */

void mouse(int x, int y) {
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
}
