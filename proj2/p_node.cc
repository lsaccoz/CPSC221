#include <cstdlib>
#include "p_node.h"

//Constructor for the p_node class
//freq : the frequency for the node being created
//c    : the value of the char for this node
//left : the left child of this node
//right: the right child of this node
p_node::p_node(int freq, char c, p_node* left, p_node* right) {
    this->freq = freq;
    this->c = c; 
    this->left = left;
    this->right = right;
}


