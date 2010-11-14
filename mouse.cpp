/**
 * mouse : handles all mouse actions
 */

void mouse(int x, int y) {
	static int prevX, prevY;
	int deltaX = x - prevX, deltaY = y - prevY, tol = 3.0;
	
	if( abs(deltaX) > 0.0 && abs(deltaY) < tol ) {
		cam.swing(deltaX);
	}
	
	glutPostRedisplay();
	prevX = x;
	prevY = y;
}
