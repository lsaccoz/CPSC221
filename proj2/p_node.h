//This class represents a node with a priority queue
class p_node {
//All public fields and methods
public:
    int freq;      //The frequency of the node, if not a leaf, it is the sum of both children's frequencies
    char c;        //The value of the character at this node, would be NULL if not a leaf
    p_node* left;  //The p_node* which is the left child of this p_node, NULL if this is a leaf
    p_node* right; //The p_node* which is the right child of this p_node, NULL if this is a leaf
    
    //Constructor 
    p_node(int freq, char c = '\0', p_node* left = NULL, p_node* right = NULL);
};


