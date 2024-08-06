## Compiler g++/clang++
CXX = g++

all: prototipo.o prototipo

prototipo.o:
	$(CXX) prototipo.cpp -c

prototipo:	prototipo.o
	$(CXX) prototipo.o -o prototipo -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f *.o prototipo