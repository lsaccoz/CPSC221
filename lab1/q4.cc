#include <cstdlib>
#include <iostream>

void moveDisks(int n, const char* FROM,
const char* VIA, const char* TO);

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0]
			<< " <number of disks>" << std::endl;
		return -1;
	}
	moveDisks(atoi(argv[1]), "A", "B", "C");
	return 0;
}

void moveDisks(int n, const char* FROM,
const char* VIA, const char* TO)
{
	if (n < 1) return;
	moveDisks(n - 1, FROM, TO, VIA);
	std::cout << "Move disk from peg "
		<< FROM << " to peg " << TO << std::endl;
	moveDisks(n - 1, VIA, FROM, TO);
	
}
