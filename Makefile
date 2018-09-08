all: main

main: main.cpp dlist.h node.h iterator.h slist.h
	g++ -std=c++11 main.cpp -o main
