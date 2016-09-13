#include <iostream>
#include <string>
#include <fstream>

int main(void) {
    std::ifstream in ("infile.txt");    // input file stream
    std::ofstream out ("outfile.txt");  // output file stream
    std::string ss;
    // Put next line in ss (discard any newline chars)
    while (getline(in,ss))
        out << ss << std::endl;  // add line to out
    std::cout << "End of program" << std::endl;
    return 0;
}
