
#include <cstdlib>
#include <iostream>
#include "pri_q.h"

using namespace std;

//Constructor for p_queue
p_queue::p_queue() {
  heap = vector<p_node*>();
}

//Insert a new node into the priority queue
void p_queue::insert(p_node* newNode) {
  int lastPos = heap.size();
  heap.insert(heap.end(), newNode);
  siftUp(lastPos);
}

//This function swaps a node up to its correct location
//within the heap, given it's original location "i"
void p_queue::siftUp(int i) {
  //if i is the root of it out of bounds
  if (i <= 0 || i >= (int)heap.size()){
      return;
  }
  
  //calculate the parent, and the determine if a swap 
  //should be performed, if it does, swap and the swapUp again
  int parent = (i - 1) / 2;
  if (heap[parent]->freq >    heap[i]->freq) {
    swap(heap[i], heap[parent]);
    siftUp(parent);
  }
}

//This function swaps a p_node at location i to its correct position within the 
//heap. "i" is the initial index of the the node within the heap
void p_queue::siftDown(int i) {
  int heapSize = heap.size();//size of the heap
  int min = i;           //the min is initially i
  int left = 2 * i + 1;  //left child
  int right = 2 * i + 2; //right child
  
  //get the lowest value
  if (left < heapSize && heap[left]->freq < heap[min]->freq)
    min = left;
  if (right < heapSize && heap[right]->freq < heap[min]->freq)
    min = right;

  // if either left or right contain the min, then swap and swapDown
  //once more recursively using min
  if (min != i) {
    swap(heap[i], heap[min]);
    siftDown(min);
  }
}

//This function deletes and return the mininum  
p_node* p_queue::deleteMin() {
  //if the heap is empty, there is no min to delete
  if (heap.empty()) 
    return NULL;

  //the first (root) node of the heap should be the smallest since 
  //it has been heapified
  p_node* min = heap[0]; 
  //removethe smallest node then swap down to restore the heap
  heap.erase(heap.begin());
  siftDown(0);

  return min;
}

//The function heapify's the heap in order to maintain a minHeap
void p_queue::heapify() {
  int size = heap.size();
  for (int i = (size - 2) / 2; i >= 0; i--)
    siftDown(i);
}

//this function returns the size of the heap, which is the size of the p_queue
int p_queue::size() {
  return heap.size();
}
