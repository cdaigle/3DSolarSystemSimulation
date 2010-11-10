/**
 * "star.h"
 */

class Star : public Sphere {
	public:
		Star(string nameIn, double radiusIn, double orbitDistance, double albeldoIn, string texturePathIn) : 
			Sphere(nameIn, radiusIn, orbitDistance, albeldoIn, texturePathIn) { }
	public:
		void draw(void);
};
