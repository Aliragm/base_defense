## Detect the operating system and set the compiler accordingly
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    CXX = clang++
else
    CXX = g++
endif

## Project object files
SRCS = ./classes/base.o ./classes/bullet.o ./classes/enemy.o ./classes/HUD.o ./classes/player.o ./classes/drops.o main.o

## Project header files
HEADERS = ./headers/base.hpp ./headers/bullet.hpp ./headers/HUD.hpp ./headers/enemy.hpp ./headers/player.hpp ./headers/drops.hpp

## Compiler flags
override CXXFLAGS += -g -Wall -pedantic

## SFML libraries (including audio)
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

## Compile all
all: base.o bullet.o enemy.o player.o drops.o HUD.o main.o project

## Compile base.cpp
base.o: $(HEADERS) ./classes/base.cpp
	$(CXX) $(CXXFLAGS) ./classes/base.cpp -c

## Compile bullet.cpp
bullet.o: $(HEADERS) ./classes/bullet.cpp
	$(CXX) $(CXXFLAGS) ./classes/bullet.cpp -c

## Compile enemy.cpp
enemy.o: $(HEADERS) ./classes/enemy.cpp
	$(CXX) $(CXXFLAGS) ./classes/enemy.cpp -c

## Compile HUD.cpp
HUD.o: $(HEADERS) ./classes/HUD.cpp
	$(CXX) $(CXXFLAGS) ./classes/HUD.cpp -c

## Compile player.cpp
player.o: $(HEADERS) ./classes/bullet.o ./classes/enemy.o ./classes/player.cpp
	$(CXX) $(CXXFLAGS) ./classes/player.cpp -c

## Compile drops.cpp
drops.o: $(HEADERS) ./classes/drops.cpp
	$(CXX) $(CXXFLAGS) ./classes/drops.cpp -c

## Compile main.cpp
main.o: $(HEADERS) main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -c

## Link all object files
project: $(HEADERS) $(SRCS)
	$(CXX) $(SRCS) $(CXXFLAGS) -o project $(SFML_LIBS)

## Clean object files and project
clean:
	rm -f *.o ./classes/*.o project

## Clean only object files
clean-obj:
	rm -f *.o ./classes/*.o

## Clean only project
clean-project:
	rm -f project °₢ 