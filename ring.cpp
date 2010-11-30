/**
 * ring : high-level abstraction for rings
 */
#include "ring.h"

void Ring :: draw(double radiusScale, Point3 currentPosition) {
	if (enabled == true)
	{		
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		GLUquadricObj *quadratic = NULL;
		quadratic = gluNewQuadric();         // Create A Pointer To The Quadric Object
		gluQuadricDrawStyle(quadratic, GLU_FILL);
		gluQuadricTexture(quadratic, GL_TRUE);      // Create Texture Coords
		gluQuadricNormals(quadratic, GLU_SMOOTH);   // Create Smooth Normals
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	// Linear Filtering
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D,textureId);

		glPushMatrix();
			glTranslated(currentPosition.x, currentPosition.y, currentPosition.z);
			glRotated(ringRotation + 90, 1, 0, 0);
		
			glBegin(GL_QUAD_STRIP);
			for (double angle=0; angle<=360; angle+= 0.2)
			{
				glNormal3f(0.0,0.0,1.0);
				glTexCoord2f (0.0, 1.0);
				glVertex3d (outerRadius * radiusScale * cos(angle), outerRadius * radiusScale * sin(angle), 0.0);
				glNormal3f (0.0, 0.0, 1.0);
				glTexCoord2f (1.0, 0.0);
				glVertex3d (innerRadius * radiusScale * cos(angle), innerRadius * radiusScale * sin(angle), 0.0);
			}
			glEnd();	
		glPopMatrix();
	}
}

void Ring :: setEnabled(bool value)
{
	enabled = value;
}

void Ring :: toggle()
{
	enabled = !enabled;
}
