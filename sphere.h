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
		Sphere(string nameIn, double radiusIn, double orbitDistance, double albeldoIn, string texturePathIn) {
			radius = radiusIn;
			orbitingDistance = orbitDistance;
			albeldo = albeldoIn;
			texturePath = texturePathIn;
			name = nameIn;
		}
		int textureId;

		void draw(double);
		double scaleOrbit(void);
		string getTexturePath(void){ return texturePath; }
		string getName(void) { return name; }
		double getRadius(double radiusScale) { return radius * radiusScale; }

		void setCurrentPosition(Point3 point){ currentPosition.set(point); }
		void setCurrentPosition(double x, double y, double z){ currentPosition.set(x,y,z);}
		Point3 getCurrentPosition(void){return currentPosition;}
};
