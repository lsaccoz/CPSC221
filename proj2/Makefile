all : clean huftree

p_node.o: p_node.cc p_node.h
	g++ -Wall -c -std=c++11 p_node.cc -o p_node.o

pri_q.o: pri_q.cc pri_q.h p_node.o
	g++ -Wall -c -std=c++11 pri_q.cc -o pri_q.o

codetree.o: codetree.cc codetree.h pri_q.o
	g++ -Wall -c -std=c++11 codetree.cc -o codetree.o

huftree.o: codetree.o codetree.h
	g++ -Wall -c -std=c++11 huftree.cc -o huftree.o

huftree : huftree.o codetree.o pri_q.o p_node.o
	g++ -Wall p_node.o pri_q.o codetree.o huftree.o -o huftree 
	
clean :
	rm -f huftree *.o

