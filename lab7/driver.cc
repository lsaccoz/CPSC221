#include "Hashtable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


void usage(char* argv[]) {
	cerr << "Usage: " << argv[0] << " scheme numberOfKeys sizeOfTable" << endl;
	exit(-1);
}

int main(int argc, char *argv[]) {
	int n, m;
	srand(time(0));

	if (argc == 1) {
		cout << endl << "RUNNING TEST CODE!!!!" << endl << endl;
		/* ADD YOUR TEST CODE HERE */
                
                for(int size = 1; size <=100; size++){
                    for(int num_keys = 0; num_keys <= 2 * size; num_keys++){
                        
                        cout << "********" << num_keys << " PIGEONS ---> " << size << " HOLES*******"
                                << endl;
                        
                        Hashtable table(size);
                        
                        cout << "LINEAR" << endl;                	
                        for (int i = 0; i < num_keys; i++)
                            table.linsert(rand() + 1);	
                        table.printStats();
                        table.clear();
                
                        cout << "DOUBLE" << endl;
                        for (int j = 0; j < num_keys; j++)
                            table.dinsert(rand() + 1);				
                        table.printStats();
                        table.clear();
                
                        cout << "QUADRATIC" << endl;
                        for (int k = 0; k < num_keys; k++)
                            table.qinsert(rand() + 1);	
                        table.printStats();
                        table.clear();                
                    }
                }
                
                ///SIZE 10,000, KEYS 7,500
                cout << "********7,500 PIGEONS ---> 10,000 HOLES*******"
                        << endl;
                int size = 10000;
                int num_keys =7500;
                Hashtable table1(size);
                
                cout << "LINEAR" << endl;                	
		for (int i = 0; i < num_keys; i++)
			table1.linsert(rand() + 1);	
		table1.printStats();
                table1.clear();
                
                cout << "DOUBLE" << endl;
		for (int j = 0; j < num_keys; j++)
			table1.dinsert(rand() + 1);				
		table1.printStats();
                table1.clear();
                
                cout << "QUADRATIC" << endl;
		for (int k = 0; k < num_keys; k++)
			table1.qinsert(rand() + 1);	
		table1.printStats();
                table1.clear();
             
                ///SIZE 100000, KEYS 90,000
                cout << "********90,000 PIGEONS ---> 100,000 HOLES********"
                        << endl;
                size = 100000;
                num_keys = 90000;
                Hashtable table2(size);
                
                cout << "LINEAR" << endl;                	
		for (int i = 0; i < num_keys; i++)
			table2.linsert(rand() + 1);	
		table2.printStats();
                table2.clear();
                
                cout << "DOUBLE" << endl;
		for (int j = 0; j < num_keys; j++)
			table2.dinsert(rand() + 1);				
		table2.printStats();
                table2.clear();
                
                cout << "QUADRATIC" << endl;
		for (int k = 0; k < num_keys; k++)
			table2.qinsert(rand() + 1);	
		table2.printStats();
                table2.clear();

		return 0;
	}
	
	if (argc != 4) {
		usage(argv);
	}
	n = atoi(argv[2]);
	m = atoi(argv[3]);
	Hashtable H(m);
	
	switch(argv[1][0]) {
	case 'l':
		for (int i=0; i<n; ++i) {
			H.linsert(rand() + 1);
		}
		//    H.print();
		cout << "Linear: ";  
		H.printStats();
		break;
	case 'q':
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() + 1);
		}
		//    H.print();
		cout << "Quadratic: ";
		H.printStats();
		break;
	case 'd':
		for (int i=0; i<n; ++i) {
			H.dinsert(rand() + 1);
		}
		//    H.print();
		cout << "Double Hashing: "; 
		H.printStats();
		break;
	default:
		usage(argv);
	}
}