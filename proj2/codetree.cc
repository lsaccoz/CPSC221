
#include <iostream>
#include "codetree.h"

using namespace std;

//Constructor for a code tree. It takes in a p_queue (Priority Queue),
//which employs a heap
CodeTree::CodeTree(p_queue *queue) {
  //While the queue is not yet at the root
  while (queue->size() > 1) {
    //remove the two smallest nodes from the p_queue at get the sum
    //of their frequencies
    p_node* first = queue->deleteMin();
    p_node* second = queue->deleteMin();
    int freq_sum = first->freq + second->freq;

    //then, using their sum, create a parent for both of them
    p_node *parent = new p_node(freq_sum, '\0', first, second);
    //then insert the new parent p_node into the priority queue
    queue->insert(parent);
  }
  //Once the Huffman algorithm has finished, last remaining node
  //will be the root of the tree, remove if from the queue and set the root
  //of the code tree to it
  root = queue->deleteMin();
}


void CodeTree::printTree() {
  printTreeHelper(root, "");
}

//Slightly modified recursion helper method provided via a
//piazza post
void CodeTree::printTreeHelper(p_node* root, string pre) {
  if (root == NULL) return;
  if (root->right == NULL) { // implies r->left == NULL
    printChar(root->c);
    cout << endl;
  } else {
    cout << "." << endl;
    cout << pre << "|`1-";
    printTreeHelper(root->right, pre + "|   ");
    cout << pre + "|   " << endl;
    cout << pre << "`-0-";
    printTreeHelper(root->left, pre + "    ");
  }
}

void CodeTree::printCode() {
  printCodeHelper(root, "");
}

//A recursive helper function used to print out the codes 
//for the generated code 
void CodeTree::printCodeHelper(p_node *head, string path) {
  if (head->c != '\0') {
    printChar(head->c);
    cout << ":" << path << endl;
  } else {
    printCodeHelper(head->left, path + "0");
    printCodeHelper(head->right, path + "1");
  }
}

//Provided function to map a chars index to it's value
void CodeTree::printChar(int ch) {
  if (ch < 16) {
    cout << "x0" << hex << ch;
  } else if (ch < 32 || ch > 126) {
    cout << "x" << hex << ch;
  } else {
    cout << "\"" << (char) ch << "\"";
  }
}
