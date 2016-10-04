// linked_list.cc -- functions for linked_list lab (cs221) 

#include "linked_list.h"
#include <vector>

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: newKey is the value for the key in the new Node 
 * POST: the new Node is now the head of the linked_list
 */
void insert(Node*& head, int newKey) {
    Node * curr = new Node;
    curr->key = newKey;
    curr->next = head;

    head = curr;
}

/**
 * Print the keys of a linked_list in order, from head to tail 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */
void print(Node* head) {
    std::cout << "[";
    for (Node* curr = head; curr != NULL; curr = curr->next) {
        std::cout << curr->key;
        if (curr->next != NULL) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

/** 
 * Returns the size (number of Nodes) of the linked_list  
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */
int size(Node* head) {
    if (!head) return 0;
    return 1 + size(head->next);
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * POST: a new vector<int> containing the keys in the correct order has been returned.  
 */
std::vector<int> to_vector(Node* head) {
    std::vector<int> result;
    for (Node* curr = head; curr != NULL; curr = curr->next) {
        result.push_back(curr->key);
    }
    return result;
}

/** 
 * Delete the last Node in the linked_list
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * POST: the last Node of the linked_list has been removed
 * POST: if the linked_list is now empty, head has been changed
 * POST: else head remains the first Node in the linked_list
 */
void delete_last_element(Node*& head) {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node * current = head;
    while (current->next && current->next->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
    /*Node * previous = head;
    Node * current = head->next;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    delete current;
    current = NULL;
    previous->next = NULL;*/

}

/**
 * Removes an existing Node (with key=oldKey) from the linked_list. 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value of the key in the Node to be removed 
 * PRE: if no Node with key=oldKey exists, the linked_list has not changed 
 * POST: if a Node with key=oldKey was found, then it was deleted
 * POST: other Nodes with key=oldKey might still be in the linked_list
 * POST: head is the new first Node of the linked_list, if updated
 */
void remove(Node*& head, int oldKey) {
    if (!head) return;

    if (head->key == oldKey) {
        Node * oldHead = head;
        head = head->next;
        delete oldHead;
        return;
    } else {
        Node * previous = head;
        Node * current = head->next;
        while (current != NULL) {
            if (current->key == oldKey) {
                previous->next = current->next;
                delete current;
                current = NULL;
            } else {
                previous = current;
                current = current->next;
            }
        }
    }
}

/**
 * Insert a new Node (with key=newKey) after an existing Node (with key=oldKey)
 * If there is no existing Node with key=oldKey, then no action.
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value to look for (in the key of an existing Node)  
 * PRE: newKey is the value of the key in the new Node (that might be inserted) 
 * POST: if no Node with key=oldKey was found, then the linked_list has not changed
 * POST: else a new Node (with key=newKey) is right after the Node with key = oldKey.
 */
void insert_after(Node* head, int oldKey, int newKey) {
    if (!head) return;

    if (head->next == NULL) {
        Node * newNode = new Node;
        newNode->next = head->next;
        newNode->key = newKey;
        head->next = newNode;
    } else {
        Node * current = head;
        while (current->next != NULL) {
            if (current->key == oldKey) {
                Node * newNode = new Node;
                newNode->next = current->next;
                newNode->key = newKey;
                current->next = newNode;
                break;
            }
            current = current->next;
        }
    }
}

/** 
 * Create a new linked_list by merging two existing linked_lists. 
 * PRE: list1 is the first Node in a linked_list (if NULL, then it is empty)
 * PRE: list2 is the first Node in another linked_list (if NULL, then it is empty)
 * POST: A new linked_list is returned that contains new Nodes with the keys from 
 * the Nodes in list1 and list2, starting with the key of the first Node of list1, 
 * then the key of the first Node of list2, etc. 
 * When one list is exhausted, the remaining keys come from the other list.
 * For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
 */
Node* interleave(Node* list1, Node* list2) {
    if (!list1) {
        Node * result = new Node;
        result = list2;
        return result;
    } else if (!list2) {
        Node * result = new Node;
        result = list1;
        return result;
    } else if (!list1 && !list2) {
        return NULL;
    } else {
        int counter = 1;
        Node * currentNode1 = list1;
        Node * currentNode2 = list2;
        Node * head = new Node;
        head->next = NULL;
        head->key = currentNode1->key;
        currentNode1 = currentNode1->next; //update currentNode1

        Node * current = head;
        while (currentNode1 || currentNode2) {
            if (counter % 2 == 1) {
                if (currentNode2) {
                    Node * newNode = new Node;
                    newNode->key = currentNode2->key;
                    newNode->next = NULL;
                    current->next = newNode;
                    current = current->next;
                    currentNode2 = currentNode2->next;
                } else if (currentNode1) {
                    Node * newNode = new Node;
                    newNode->key = currentNode1->key;
                    newNode->next = NULL;
                    current->next = newNode;
                    current = current->next;
                    currentNode1 = currentNode1->next;
                } else {
                    break;
                }
            } else {
                if (currentNode1) {
                    Node * newNode = new Node;
                    newNode->key = currentNode1->key;
                    newNode->next = NULL;
                    current->next = newNode;
                    current = current->next;
                    currentNode1 = currentNode1->next;
                } else if (currentNode2) {
                    Node * newNode = new Node;
                    newNode->key = currentNode2->key;
                    newNode->next = NULL;
                    current->next = newNode;
                    current = current->next;
                    currentNode2 = currentNode2->next;
                } else {
                    break;
                }
            }
            counter++;
        }
        return head;
    }
}
