/**
 * sphere.h
 */

class Sphere
{
	private:
		double radius;
		double albeldo;            //reflectiveness
		string name, texturePath;
		Point3 currentPosition;
		Vector3 rotationalAxis;
	public:
		// Constructor
		Sphere(){}
		Sphere(string nameIn, double radiusIn, double orbitDistanceIn, double albeldoIn, double tiltDegreeIn, string texturePathIn) 
		{
			radius = radiusIn;
			orbitDistance = orbitDistanceIn;
			albeldo = albeldoIn;
			texturePath = texturePathIn;
			name = nameIn;
			orbitDegree = 0.0;
			tiltDegree = tiltDegreeIn;
			rotationalAxis.set(0.0, cos(tiltDegree*DEG2RAD), sin(tiltDegree*DEG2RAD));
		}
		int textureId;
		double orbitDegree, orbitDistance, tiltDegree;

		// Implemented in sphere.cpp
		void draw(double);
		void position(void);
		void rotate(void);
		void create(double);
		void applyTexture(void);
		void applyLighting(void);
		void applyMaterial(void);

		// Implemented here
		string getTexturePath(void)
		{ 
			return texturePath; 
		}
		void setCurrentPosition(Point3 point)
		{
			currentPosition.set(point);
		}
		void setCurrentPosition(double x, double y, double z)
		{
			currentPosition.set(x,y,z);
		}
		Point3 getCurrentPosition(void)
		{
			return currentPosition;
		}
		string getName(void)
		{
			return name;
		}
};
