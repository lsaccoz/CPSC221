/**
 * [So make a test suite that finds something
 * and then removes it immediately.]
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm> // for find and sort

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

    // the Insert for loop inserts random elements from
    // 0 to MAX-1 and prints them out.
    for (i = 0; i < size; i++)
    {
        int input = randInt(1,MAX_VAL);
        while (contains(inputs, input))
            input = randInt(1, MAX_VAL);
        cout << "I " << input << endl;
        inputs.push_back(input);
    }    

    // this for loop Finds what the inputs were in reversed
    // order, guaranteeing worst case for Find in unsorted
    // linked-list (O(n)). Then, since it is move-to-front
    // on find, Remove said element immediately, guaranteeing
    // O(1) time because it will always be at the front.
    for (i = size-1; i >= 0 ; i--)
    {
        cout << "F " << inputs[i] << endl;
        cout << "R " << inputs[i] << endl;
    }

}
