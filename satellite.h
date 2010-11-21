/**
 * satellite.h
 */

class Satellite : public Sphere{
	public:
		Satellite(string nameIn, double radiusIn, double orbitDistance, double albeldoIn, string texturePathIn) : 
			Sphere(nameIn, radiusIn, orbitDistance, albeldoIn, texturePathIn) { }
		void draw(void);
		void move(void);
	private:
};
