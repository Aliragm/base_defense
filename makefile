## Compiler g++/clang++
CXX = g++
SRCS = ./classes/base.o ./classes/bullet.o ./classes/enemy.o ./classes/player.o main.o
HEADERS = ./headers/base.hpp ./headers/bullet.hpp ./headers/enemy.hpp ./headers/player.hpp

all: base.o bullet.o enemy.o player.o main.o project

base.o:	$(HEADERS) ./classes/base.cpp
	$(CXX) ./classes/base.cpp -c

bullet.o:	$(HEADERS) ./classes/bullet.cpp
	$(CXX) ./classes/bullet.cpp -c

enemy.o:	$(HEADERS) ./classes/enemy.cpp
	$(CXX) ./classes/enemy.cpp -c

player.o:	$(HEADERS) ./classes/bullet.o ./classes/enemy.o ./classes/player.cpp
	$(CXX) ./classes/player.cpp -c

main.o:	$(HEADERS) prototipo.cpp
	$(CXX) prototipo.cpp -c

project:	$(HEADERS) $(SRCS)
	$(CXX) $(SRCS) -o project -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f *.o ./classes/*.o project

clean-obj:
	rm -f *.o ./classes/*.o

clean-project:
	rm -f project