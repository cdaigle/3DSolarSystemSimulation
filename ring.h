/**
 * Ring Class - deals with the rings for the planets
 */

class Ring
{
	private:
		string texturePath;
		string name;
		double innerRadius;
		double outerRadius;
		double ringRotation;
		bool enabled;

	public:
		Ring(string nameIn, double innerRadiusIn, double outerRadiusIn, string texturePathIn, int planetIn, double rotationIn) {
			innerRadius = innerRadiusIn;
			outerRadius = outerRadiusIn;
			texturePath = texturePathIn;
			name = nameIn;
			planetId = planetIn;
			ringRotation = rotationIn;
			enabled = true;
		}
		int textureId;
		int planetId;

		double getInnerRadius(void) {
			return innerRadius;
		}
		double getOuterRadius(void) {
			return outerRadius;
		}

		void draw(double, Point3);
		void toggle(void);
		void setEnabled(bool);
		string getTexturePath(void){ return texturePath; }
		string getName(void) { return name; }
};
