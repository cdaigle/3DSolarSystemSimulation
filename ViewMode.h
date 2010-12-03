class ViewMode
{
	private:
		string name;

	public:
		double planetRadiusScale;
		double planetRadiusScaleModifier;
		double starRadiusScale;
		double starRadiusScaleModifier;
		double satelliteRadiusScale;
		double satelliteRadiusScaleModifier;

		double planetOrbitScale;
		double planetOrbitScaleModifier;
		double satelliteOrbitScale;
		double satelliteOrbitScaleModifier;
		
		double hourIncrement;
		double hourIncrementModifier;
		
		double camIncrement;
		
		double scaleFactor;
		
		double initCameraDistance;

		int lookAtId;
		Point3 initEyePos;
		Point3 initLookPos;
		Camera cam;

		ViewMode(
			string nameIn, 
			double pRS, 
			double pRSM, 
			double starRS, 
			double starRSM, 
			double pOS, 
			double pOSM, 
			double hI, 
			double hIM, 
			double cD, 
			int oBI, 
			double satelliteRS, 
			double satelliteRSM, 
			double satelliteOS, 
			double satelliteOSM	)
		{
			name = nameIn;
			
			planetRadiusScale = pRS;
			planetRadiusScaleModifier = pRSM;
			starRadiusScale = starRS;
			starRadiusScaleModifier = starRSM;
			satelliteRadiusScale = satelliteRS;
			satelliteRadiusScaleModifier = satelliteRSM;

			planetOrbitScale = pOS;
			planetOrbitScaleModifier = pOSM;
			satelliteOrbitScale = satelliteOS;
			satelliteOrbitScaleModifier = satelliteOSM;
			
			hourIncrement = hI;
			hourIncrementModifier = hIM;
			
			initCameraDistance = cD;

			lookAtId = oBI;
			
			camIncrement = 1.0;
			
			initEyePos.set(-10.0f, 1.2f, 0.0f);
			initLookPos.set(0.0f, 0.0f, 0.0f);
			cam.init(initCameraDistance);
			
			scaleFactor = 0.5;
		}
		void incPlanetRadiusScale(void);
		void decPlanetRadiusScale(void);

		void incStarRadiusScale(void);
		void decStarRadiusScale(void);
		
		void incSatelliteRadiusScale(void);
		void decSatelliteRadiusScale(void);

		void incPlanetOrbitScale(void);
		void decPlanetOrbitScale(void);
		
		void incSatelliteOrbitScale(void);
		void decSatelliteOrbitScale(void);

		void incHourIncrement(void);
		void decHourIncrement(void);
		
		void incCamIncrement(void);
		void decCamIncrement(void);
		
		void incScale(void);
		void decScale(void);
		
		void setupCam(void);

		void reset(void);
		
		string getName(void)
		{
			return name;
		}
};
