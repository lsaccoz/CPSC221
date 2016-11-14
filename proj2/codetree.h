#include "pri_q.h"

class CodeTree {
    p_node* root;
public:
    CodeTree(p_queue*);
    void printTree();
    void printCode();

private:
    void printChar(int);
    void printCodeHelper(p_node *head, std::string trail);
    void printTreeHelper(p_node * r, std::string pre);
};


