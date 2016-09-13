#include <iostream>

const int size = 10;
int array[size];

void print_array();
void fill_array();
void fill_array(int first_value, int increment);

int main(void)
{
	// a
	fill_array();
	print_array();
	
	// b
	fill_array(4, 2);
	print_array();
	fill_array(0, 5);
	print_array();
	
	return 0;
}

void print_array()
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void fill_array()
{
	for (int i = 0; i < size; i++)
		array[i] = i + 1;
}

void fill_array(int first_value, int increment)
{
	int val = first_value;
	for (int i = 0; i < size; i++)
	{
		array[i] = val;
		val += increment;
	}
}