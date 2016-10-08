
FLAGS = -g -Wall -Wno-sign-compare -std=c++11

all: lab6

lab6: BSTNode.o BST.o lab6.o
	g++ $(FLAGS) BSTNode.o BST.o lab6.o -o lab6

BSTNode.o: BSTNode.cpp BSTNode.h
	g++ $(FLAGS) -c BSTNode.cpp -o BSTNode.o

BST.o: BST.cpp BST.h
	g++ $(FLAGS) -c BST.cpp -o BST.o

lab6.o: lab6.cpp
	g++ $(FLAGS) -c lab6.cpp -o lab6.o

clean:
	rm -f *.o lab6

