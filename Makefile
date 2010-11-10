CFLAGS= -I/usr/X11R6/include -I/usr/local/include
LDFLAGS= -L/usr/X11R6/lib -L/usr/local/lib -lGL -lGLU -lm -lglut 

BINARIES=planetSimulator

all: $(BINARIES)

clean:	
	-rm *.o $(BINARIES)

planetSimulator : planetSimulator.o 
	g++ $(LDFLAGS) $^ -o planetSimulator 

planetSimulator.o: planetSimulator.cpp 
	g++ -c $(CFLAGS) planetSimulator.cpp

depend:
	makedepend *.cpp

