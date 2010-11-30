/**
 * sphere : high-level abstraction for spheres.
 *          Moons and Planets extend this.
 */
#include "sphere.h"

void Sphere :: draw(double radiusScale) 
{
	glPushMatrix();
		position();
		rotate();
		create(radiusScale);
	glPopMatrix();	

	glEnable(GL_DEPTH_TEST);
}

void Sphere :: applyTexture()
{
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, textureId);
}
void Sphere :: position()
{
	glTranslated(currentPosition.x, currentPosition.y, currentPosition.z);
}

void Sphere :: rotate()
{
	glRotated(orbitDegree, rotationalAxis.x, rotationalAxis.y, rotationalAxis.z);
}

void Sphere :: create(double radiusScale)
{
	applyTexture();
	applyMaterial();
	GLUquadricObj *quadratic = NULL;
	quadratic = gluNewQuadric();                // Create A Pointer To The Quadric Object
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricTexture(quadratic, GL_TRUE);      // Create Texture Coords
	gluQuadricNormals(quadratic, GLU_SMOOTH);   // Create Smooth Normals
	glRotated (tiltDegree, 1, 0, 0);
	glRotated (270, 1, 0, 0);
	gluSphere(quadratic, radius*radiusScale, 40, 40);
}

void Sphere :: applyMaterial()
{
	
}
