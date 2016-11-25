/**
 * This generator produces essentially random inputs
 * for all three of Insert, Find, and Remove operations.
 * It outputs n/3 Insertions, then n/3 Finds, then n/3 Removals.
 */

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm> // for find

using namespace std;

int MAX_VAL = 1000;

int randInt(int a, int b)
{
    return a + (rand() % (b-a)); // in [a,b)
}

bool contains(vector<int> v, int key)
{
    return find(v.begin(), v.end(), key) != v.end();
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cerr << "Wrong number of arguments!" << endl;
        return 1;
    }

    srand(time(0));
    int n = atoi(argv[1]);
    int size = n/3;

    if (size >= MAX_VAL)
       MAX_VAL = size*10;

    int i;

    vector<int> inputs;
    vector<int> inputs_copy;

    // the Insert for loop inserts random elements from
    // 0 to MAX-1 and prints them out.
    for (i = 0; i < size; i++)
    {
        int input = randInt(1,MAX_VAL);
        while (contains(inputs, input))
            input = randInt(1, MAX_VAL);
        cout << "I " << input << endl;
        inputs.push_back(input);
        inputs_copy.push_back(input);
    }    

    // the Find for loop finds random elements (just a random order)
    // from the input array, deleting stuff from it one at a time.
    for (i = 0; i < size ; i++)
    {
        int index = randInt(0,size-i); // size-i is the new size of the vector
        cout << "F " << inputs[index] << endl;
        inputs.erase(inputs.begin()+index);
    }
    
    // the Remove for loop remove alternating elements of indices
    // array by starting in the middle and going one element
    // to the right, then to the left, and so on and so forth.
    int index = size/2-1; bool alt = true;
    for (i = 1; index >= 0 && index < size; i++)
    {
        cout << "R " << inputs_copy[index] << endl;
        index += alt ? i : -i;
        alt = !alt;
    }

}
