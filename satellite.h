/**
 * satellite.h
 */

class Satellite : public Sphere{
	public:
		Satellite(string nameIn, double radiusIn, double orbitDistance, double albeldoIn, double daysToOrbitIn, double inclinationIn, double eccentricityIn, string texturePathIn, int planetIdIn) : 
			Sphere(nameIn, radiusIn, orbitDistance, albeldoIn, texturePathIn) { 
			daysToOrbit = daysToOrbitIn;
			inclination = inclinationIn;
			eccentricity = eccentricityIn;
			planetId = planetIdIn;
			enabled = true;
			orbitEnabled = true;
		}
		void draw(void);
		void move(Planet);
		void toggle(void);
		void toggleOrbit(void);
		void drawOrbit(void);
		double getOrbitX(double);
		double getOrbitY(double);
		double getOrbitZ(double);
		int getPlanetId(void);
	private:
		int planetId;
		bool enabled;
		bool orbitEnabled;
		double daysToOrbit;
		double inclination;
		double eccentricity;
};
