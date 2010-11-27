/**
 * satellite.h
 */

class Satellite : public Sphere
{
	public:
		Satellite() : Sphere() {}
		Satellite(
			string nameIn, 
			double radiusIn, 
			double orbitDistance, 
			double albeldoIn, 
			double daysToOrbitIn, 
			double inclinationIn, 
			double eccentricityIn, 
			string texturePathIn, 
			int planetIdIn,
			double planetInclinationIn
		) :	Sphere(
			nameIn,
			radiusIn,
			orbitDistance,
			albeldoIn,
			0.0,
			texturePathIn
		) 
		{ 
			daysToOrbit = daysToOrbitIn;
			inclination = inclinationIn;
			eccentricity = eccentricityIn;
			planetId = planetIdIn;
			enabled = true;
			orbitEnabled = true;
			planetInclination = planetInclinationIn;
			planetPosition.set(0.0f, 0.0f, 0.0f);
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
		bool isEnabled(void);
		bool isOrbitEnabled(void);
		void setEnabled(bool);
		void setOrbitEnabled(bool);

	private:
		int planetId;
		bool enabled, orbitEnabled;
		double daysToOrbit, inclination, eccentricity, planetInclination;
		Point3 planetPosition;
};
