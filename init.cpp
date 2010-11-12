/**
 * Init : contains init code for planet simulation
 */

#define NUM_PLANETS 9
#define NUM_VIEWMODES 2

ViewMode viewModes[NUM_VIEWMODES] = {
	ViewMode("SolarSystemView", 0.000065, 0.000001, 0.000009, 0.0, 0.00000013, 0.00000001, 1000.0, 50.0),
	ViewMode("EarthView", 0.000065, 0.000001, 0.000009, 0.0, 0.00000013, 0.00000001, 1000.0, 50.0)
};

Camera cam;

#include "sphere.cpp"
#include "star.cpp"
#include "planet.cpp"
#include "moon.cpp"

//Radius, orbit, albeldo, texturePath, 
Star Sun("Sun", 695000.0, 0.0, 1.0, "sunmap.bmp");                                         //Sun

//name, radius, distanceFromSun, albeldo, daysToOrbit, inclination, eccentricity, texture map
Planet planets[NUM_PLANETS] = {
	Planet("Mercury", 2400.0, 57910000.0, 0.11, 87.97, 7.0, 0.21, "mercurymap.bmp"),       //Mercury
	Planet("Venus", 6052.0, 108200000.0, 0.65, 224.70, 3.39, 0.01, "venusmap.bmp"),        //Venus
	Planet("Earth", 6378.0, 149600000.0, 0.30, 365.26, 0.0, 0.02, "earthmap.bmp"),         //Earth
	Planet("Mars", 3397.0, 227940000.0, 0.15, 686.98, 1.85, 0.09, "marsmap.bmp"),          //Mars
	Planet("Jupiter", 71492.0, 778330000.0, 0.52, 4332.71, 1.31, 0.05, "jupitermap.bmp"),  //Jupiter
	Planet("Saturn", 60268.0, 1429400000.0, 0.47, 10759.50, 2.49, 0.06, "saturnmap.bmp"),  //Saturn
	Planet("Uranus", 25559.0, 2870990000.0, 0.51, 30685.0, 0.77, 0.05, "uranusmap.bmp"),   //Uranus
	Planet("Neptune", 24766.0, 4504300000.0, 0.41, 60190.0, 1.77, 0.01, "neptunemap.bmp"), //Neptune
	Planet("Pluto", 1150.0, 5913520000.0, 0.55, 90550.0, 17.15, 0.25, "plutomap.bmp" )     //Pluto
};

RGBpixmap pixmaps[NUM_PLANETS + 1];  //for textures

void setupLighting(void) {
	GLfloat light0_position[] = {0.0f, 0.0f, 0.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	// set the light source properties (white)
	GLfloat lightWhite_ambient[] = {0.5, 0.5, 0.5, 1.0f};
	GLfloat lightWhite_diffuse[] = {0.9, 0.9, 0.7, 1.0f};
	GLfloat lightWhite_specular[] = {1.0, 1.0, 1.0, 1.0f};

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightWhite_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightWhite_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightWhite_specular);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void init(void) {
	setupLighting();
	
	// Initialize textures
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	Sun.textureId = 3000;
	int value = pixmaps[NUM_PLANETS].readBMPFile(Sun.getTexturePath());
	pixmaps[NUM_PLANETS].setTexture(Sun.textureId);

	for( int i = 0; i < NUM_PLANETS; i++ ) {
		planets[i].textureId = 3001 + i;									//Assign texture id
		int value = pixmaps[i].readBMPFile(planets[i].getTexturePath());    //make pixmap from image
		pixmaps[i].setTexture(planets[i].textureId);        				//create texture
	}
}
