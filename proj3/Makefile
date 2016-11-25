all : clean generator0

generator0.o: generator0.cc
	g++ -Wall -c -std=c++11 generator0.cc -o generator0.o

generator0: generator0.o
	g++ -Wall generator0.o -o generator0

clean :
	rm -f *.o generator0 
