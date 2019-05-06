CCX=g++ -g -Wall

all: ./obj/Forme2D.o

mainGraph: ./mainGraph.cpp %.o
	g++ -g -Wall -o ./bin/mainGraph

mainTest: ./mainTest.cpp %.o
	g++ -g -Wall -o ./bin/mainTest

./obj/Forme2D.o: ./src/Forme2D.cpp ./src/Forme2D.h
	g++ -g -Wall -c ./src/Forme2D.cpp

clean:
	rm -rf *~ *.o all




