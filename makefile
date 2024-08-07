## Compiler g++/clang++
CXX = g++
SRCS = ./classes/base.o ./classes/bullet.o ./classes/enemy.o ./classes/player.o main.o
HEADERS = ./headers/base.hpp ./headers/bullet.hpp ./headers/enemy.hpp ./headers/player.hpp
override CXXFLAGS += -g -Wall -pedantic

all: base.o bullet.o enemy.o player.o main.o project

base.o:	$(HEADERS) ./classes/base.cpp
	$(CXX) $(CXXFLAGS) ./classes/base.cpp -c

bullet.o:	$(HEADERS) ./classes/bullet.cpp
	$(CXX) $(CXXFLAGS) ./classes/bullet.cpp -c

enemy.o:	$(HEADERS) ./classes/enemy.cpp
	$(CXX) $(CXXFLAGS) ./classes/enemy.cpp -c

player.o:	$(HEADERS) ./classes/bullet.o ./classes/enemy.o ./classes/player.cpp
	$(CXX) $(CXXFLAGS) ./classes/player.cpp -c

main.o:	$(HEADERS) main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -c

project:	$(HEADERS) $(SRCS)
	$(CXX) $(SRCS) $(CXXFLAGS) -o project -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f *.o ./classes/*.o project

clean-obj:
	rm -f *.o ./classes/*.o

clean-project:
	rm -f project