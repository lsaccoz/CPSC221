#include <vector>
#include "p_node.h"

//This class represents 
class p_queue {
    //the heap used to represent the priority queue
    std::vector<p_node*> heap;
    
//All public methods for the priority queue
public:  
    void insert(p_node* node); //Insert into the p_queue
    p_node* deleteMin();       //Remove a p_node from the p_queue and return it  
    int size();               //Return the size of the p_queue
     p_queue();                //Constructor
private:
    void heapify();            //Perform "heapify" on the vector to create a heap
    void siftUp(int i);       //Swap up within the heap
    void siftDown(int i);     //Swap down within the heap
};

