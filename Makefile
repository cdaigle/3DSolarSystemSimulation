CFLAGS= -I/usr/X11R6/include -I/usr/local/include
LDFLAGS= -L/usr/X11R6/lib -L/usr/local/lib -lGL -lGLU -lm -lglut 

BINARIES=solarSystemSimulator

all: $(BINARIES)

clean:	
	-rm *.o $(BINARIES)

planetSimulator : solarSystemSimulator.o 
	g++ $(LDFLAGS) $^ -o solarSystemSimulator 

planetSimulator.o: solarSystemSimulator.cpp 
	g++ -c $(CFLAGS) solarSystemSimulator.cpp

depend:
	makedepend *.cpp

