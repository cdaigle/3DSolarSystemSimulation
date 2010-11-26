/**
 * sphere.h
 */

class Sphere{
	private:
		double radius;
		Point3 currentPosition;
		double albeldo;            //reflectiveness
		double orbitingDistance;
		string texturePath;
		string name;
	public:
		// Constructor
		Sphere(){}
		Sphere(string nameIn, double radiusIn, double orbitDistance, double albeldoIn, string texturePathIn) {
			radius = radiusIn;
			orbitingDistance = orbitDistance;
			albeldo = albeldoIn;
			texturePath = texturePathIn;
			name = nameIn;
		}
		int textureId;

		// Implemented in sphere.cpp
		void draw(double);
		double scaleOrbit(void);

		// Implemented here
		string getTexturePath(void){ return texturePath; }
		string getName(void) { return name; }
		double getRadius(double radiusScale) { return radius * radiusScale; }
		void setCurrentPosition(Point3 point){ currentPosition.set(point); }
		void setCurrentPosition(double x, double y, double z){ currentPosition.set(x,y,z);}
		Point3 getCurrentPosition(void){return currentPosition;}
};
