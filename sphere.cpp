/**
 * sphere : high-level abstraction for spheres.
 *          Moons and Planets will extend this.
 */
#include "sphere.h"

void Sphere :: draw(double radiusScale) {
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
	gluSphere(quadratic, radius*radiusScale, 20, 20);
	glPopMatrix();	
   
   glEnable(GL_DEPTH_TEST);

	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

//Returns the scaled orbit distance
double Sphere :: scaleOrbit() {
	return orbitingDistance * orbitScale;
}
