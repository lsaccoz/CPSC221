/**
 * [So make a test filled with random elements.
 * but  then takes out something thats not in it.
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

void sortlist(vector<int> &v)
{
    sort(v.begin(), v.end());
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

    // this for loop Finds random elements. In sorted rezisable
    // array this should take lg n time cause binary search.
    // -*- doing it in cool different order just in case -*-
    //int index = size/2-1; bool alt = true;
    //for (i = 1; index >= 0 && index < size; i++)
    //{
    //    cout << "F " << inputs[index] << endl;
    //    index += alt ? i : -i;
    //    alt = !alt;
    //}

    //sortlist(inputs);
    int notAnInput = MAX_VAL + 2;
    for (i = 0; i < 2*size; i++)
    {
        cout << "F " << notAnInput << endl;
    }

}
