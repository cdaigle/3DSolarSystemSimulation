/**
 *  Deals with the different viewing modes
 */

#include "ViewMode.h"

void ViewMode :: incPlanetRadiusScale(void)
{
	planetRadiusScale += planetRadiusScaleModifier;
}
void ViewMode :: decPlanetRadiusScale(void)
{
	planetRadiusScale -= planetRadiusScaleModifier; 
	if( planetRadiusScale <= 0.0 )
	{
		planetRadiusScale = 0.000001;
	}
}

void ViewMode :: incStarRadiusScale(void)
{
	starRadiusScale += starRadiusScaleModifier;
}
void ViewMode :: decStarRadiusScale(void)
{
	starRadiusScale -= starRadiusScaleModifier; 
	if( starRadiusScale <= 0.0 )
	{
		starRadiusScale = 0.000001;
	}
}

void ViewMode :: incSatelliteRadiusScale(void) 
{ 
	satelliteRadiusScale += satelliteRadiusScaleModifier;
}
void ViewMode :: decSatelliteRadiusScale(void)
{
	satelliteRadiusScale -= satelliteRadiusScaleModifier; 
	if( satelliteRadiusScale <= 0.0 )
	{
		satelliteRadiusScale = 0.000001;
	}
}

void ViewMode :: incPlanetOrbitScale(void)
{
	planetOrbitScale += planetOrbitScaleModifier;
}
void ViewMode :: decPlanetOrbitScale(void)
{
	planetOrbitScale -= planetOrbitScaleModifier;
	if( planetOrbitScale <= 0.0 )
	{
		planetOrbitScale = 0.00001;
	}
}

void ViewMode :: incSatelliteOrbitScale(void)
{
	satelliteOrbitScale += satelliteOrbitScaleModifier;
}
void ViewMode :: decSatelliteOrbitScale(void)
{
	satelliteOrbitScale -= satelliteOrbitScaleModifier;
	if( satelliteOrbitScale <= 0.0 )
	{
		satelliteOrbitScale = 0.00001;
	}
}

void ViewMode :: incHourIncrement(void)
{
	hourIncrement += hourIncrementModifier;
}
void ViewMode :: decHourIncrement(void)
{
	hourIncrement -= hourIncrementModifier;
}

void ViewMode :: setupCam()
{
	Vector3 up(0.0, 1.0, 0.0);
	cam.set(initEyePos, initLookPos, up);
	cam.setShape(30.0f, winWidth/(double)winHeight, 0.01f, 1200.0f);
}

void ViewMode :: incScale()
{
	planetRadiusScale = planetRadiusScale / scaleFactor;
	planetRadiusScaleModifier = planetRadiusScaleModifier / scaleFactor;
	starRadiusScale = starRadiusScale / scaleFactor;
	starRadiusScaleModifier = starRadiusScaleModifier / scaleFactor;
	satelliteRadiusScale = satelliteRadiusScale / scaleFactor;
	satelliteRadiusScaleModifier = satelliteRadiusScaleModifier / scaleFactor;

	planetOrbitScale = planetOrbitScale / scaleFactor;
	planetOrbitScaleModifier = planetOrbitScaleModifier / scaleFactor;
	satelliteOrbitScale = satelliteOrbitScale / scaleFactor;
	satelliteOrbitScaleModifier = satelliteOrbitScaleModifier / scaleFactor;
	
	setupCam();
}

void ViewMode :: decScale()
{
	planetRadiusScale = planetRadiusScale * scaleFactor;
	planetRadiusScaleModifier = planetRadiusScaleModifier * scaleFactor;
	starRadiusScale = starRadiusScale * scaleFactor;
	starRadiusScaleModifier = starRadiusScaleModifier * scaleFactor;
	satelliteRadiusScale = satelliteRadiusScale * scaleFactor;
	satelliteRadiusScaleModifier = satelliteRadiusScaleModifier * scaleFactor;

	planetOrbitScale = planetOrbitScale * scaleFactor;
	planetOrbitScaleModifier = planetOrbitScaleModifier * scaleFactor;
	satelliteOrbitScale = satelliteOrbitScale * scaleFactor;
	satelliteOrbitScaleModifier = satelliteOrbitScaleModifier * scaleFactor;
	
	setupCam();
}

void ViewMode :: reset()
{
	setupCam();
}

void ViewMode :: incCamIncrement()
{
	camIncrement += 0.10;
}

void ViewMode :: decCamIncrement()
{
	camIncrement -= 0.10;
	if (camIncrement <= 0.0)
	{
		camIncrement = 0.10;
	}
}
