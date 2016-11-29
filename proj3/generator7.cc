#include <iostream>
#include <cstdlib> 

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        std::cerr << "Wrong number of arguments!" << std::endl;
        return 1;
    }
    int n = atoi(argv[1]);

    for(int i = 0; i < n / 3; i++){
        cout << "I " << i << endl;
    }
    
    for(int i = 0; i < n / 3; i++){
        cout << "F " << i << endl;
        cout << "R " << i << endl;
    }
    
    return 0;
}
