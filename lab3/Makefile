all : dates lists 
	echo "all compiled"

CDate.o : CDate.cc CDate.h 
	g++ -Wall -c -std=c++11 CDate.cc -o CDate.o

dates : dates.cc CDate.o 
	g++ -Wall -std=c++11 dates.cc CDate.o -o dates

linked_list.o : linked_list.cc linked_list.h
	g++ -Wall -c  linked_list.cc -o linked_list.o

lists.o : lists.cc linked_list.h
	g++ -std=c++11 -Wall -c lists.cc -o lists.o

lists : lists.o linked_list.o
	g++ -Wall lists.o linked_list.o -o lists 

clean :
	rm -f dates CDate.o linked_list.o lists.o lists
 
