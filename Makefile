# Makefile

all: runMovies tests

runMovies : main.cpp movies.cpp movies.h
	g++ -o runMovies main.cpp movies.cpp

tests : movies.cpp tests.cpp tests.h
	g++ -o tests movies.cpp tests.cpp

clean :
	rm runMovies tests

