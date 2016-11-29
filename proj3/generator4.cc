#include <iostream>
#include <cstdlib> // for atoi

int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        std::cerr << "Wrong number of arguments!" << std::endl;
        return 1;
    }
    int n = atoi(argv[1]);

    // insert sequential values
    for (int i = 1; i <= n / 4; i++) {
        std::cout << "I " << i << std::endl;
    }

    // find 1 several times
    for (int i = 1; i <= n / 4; i++) {
        std::cout << "F " << 1 << std::endl;
    }

    // find all of the elements inserted
    for (int i = 1; i <= n / 4; i++) {
        std::cout << "F " << i << std::endl;
    }

    // find the value 16 several times
    for (int i = 1; i <= n / 4; i++) {
        std::cout << "F " << 16 << std::endl;
    }

    return 0;
}