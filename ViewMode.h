class ViewMode{
	private:
		string name;
		
		double planetRadiusScale;
		double planetRadiusScaleModifier;
		double starRadiusScale;
		double starRadiusScaleModifier;
		double orbitScale;
		double orbitScaleModifier;
		
		double hourIncrement;
		double hourIncrementModifier;
		
		double cameraDistance;

		int orbitBodyId;
	public:
		ViewMode(string nameIn, double pRS, double pRSM, double sRS, double sRSM, double oS, double oSM, double hI, double hIM, double cD, int oBI) {
			name = nameIn;
			
			planetRadiusScale = pRS;
			planetRadiusScaleModifier = pRSM;
			starRadiusScale = sRS;
			starRadiusScaleModifier = sRSM;
			orbitScale = oS;
			orbitScaleModifier = oSM;
			
			hourIncrement = hI;
			hourIncrementModifier = hIM;
			
			cameraDistance = cD;

			orbitBodyId = oBI;
		}
		void incrementPlanetRadiusScale(void) { 
			planetRadiusScale += planetRadiusScaleModifier;
		}
		void decrementPlanetRadiusScale(void) {
			planetRadiusScale -= planetRadiusScaleModifier; 
			if( planetRadiusScale <= 0.0 ) {
				planetRadiusScale = 0.0;
			}
		}
		double getPlanetRadiusScale(void) {
			return planetRadiusScale;
		}
		double getPlanetRadiusScaleModifier(void) {
			return planetRadiusScaleModifier;
		}

		void incrementStarRadiusScale(void) {
			starRadiusScale += starRadiusScaleModifier;
		}
		void decrementStarRadiusScale(void) {
			starRadiusScale -= starRadiusScaleModifier; 
			if( starRadiusScale <= 0.0 ) {
				starRadiusScale = 0.0;
			}
		}
		double getStarRadiusScale(void) {
			return starRadiusScale;
		}
		double getStarRadiusScaleModifier(void) {
			return starRadiusScaleModifier;
		}

		void incrementOrbitScale(void) {
			orbitScale += orbitScaleModifier;
		}
		void decrementOrbitScale(void) {
			orbitScale -= orbitScaleModifier;
			if( orbitScale <= 0.0 ) {
				orbitScale = 0.0;
			}
		}
		double getOrbitScale(void) {
			return orbitScale;
		}
		double getOrbitScaleModifier(void) {
			return orbitScaleModifier;
		}

		void incrementHourIncrement(void) {
			hourIncrement += hourIncrementModifier;
		}
		void decrementHourIncrement(void) {
			hourIncrement -= hourIncrementModifier;
			if( hourIncrement <= 0.0 ) {
				hourIncrement = 0.0;
			}
		}
		double getHourIncrement(void) {
			return hourIncrement;
		}
		double getHourIncrementModifier(void) {
			return hourIncrementModifier;
		}
		
		double getInitialCameraDistance(void) {
			return cameraDistance;
		}
		int getId(void) {
			return orbitBodyId;
		}
};
