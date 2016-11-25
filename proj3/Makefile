all : clean generator0 generator1 generator2 cleano

generator0.o: generator0.cc
	g++ -Wall -c -std=c++11 generator0.cc -o generator0.o

generator0: generator0.o
	g++ -Wall generator0.o -o generator0

generator1.o: generator1.cc
	g++ -Wall -c -std=c++11 generator1.cc -o generator1.o

generator1: generator1.o
	g++ -Wall generator1.o -o generator1

generator2.o: generator2.cc
	g++ -Wall -c -std=c++11 generator2.cc -o generator2.o

generator2: generator2.o
	g++ -Wall generator2.o -o generator2

cleano:
	rm -f *.o

clean :
	rm -f *.o generator0 generator1 generator2
