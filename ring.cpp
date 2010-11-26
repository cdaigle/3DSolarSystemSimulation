/**
 * ring : high-level abstraction for rings
 */
#include "ring.h"

void Ring :: drawRing(double radiusScale, Point3 currentPosition) {
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	GLUquadricObj *quadratic = NULL;
	quadratic = gluNewQuadric();         // Create A Pointer To The Quadric Object
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricTexture(quadratic, GL_TRUE);      // Create Texture Coords
	gluQuadricNormals(quadratic, GLU_SMOOTH);   // Create Smooth Normals
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	// Linear Filtering
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        //glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
       	//glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	//glEnable(GL_TEXTURE_GEN_S);
	//glEnable(GL_TEXTURE_GEN_T);
	glBindTexture(GL_TEXTURE_2D,textureId);
	glPushMatrix();
	glTranslated(currentPosition.x, currentPosition.y, currentPosition.z);
	glRotated (90, 1, 0, 0);
	
       double pi = 3.14159265;
       double twopi = 2 * pi;

	//for (double i = 0; i <= twopi; i+= pi/2) {
	//	gluPartialDisk(quadratic, innerRadius*radiusScale, outerRadius*radiusScale, 40, 40, i, i + pi/2);
	//}

	gluDisk(quadratic, innerRadius*radiusScale, outerRadius*radiusScale, 40, 40);
	glPopMatrix();	
   
   glEnable(GL_DEPTH_TEST);

	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}
