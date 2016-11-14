#include <iostream>
#include <fstream>
#include <algorithm>
#include "codetree.h"

// Print the Huffman code tree and list of codes for a given text file.

//If the user incorrectly calls the program from the terminal
void usage() {
  std::cerr << "Usage: huftree text.txt\n";
  throw std::exception();
}

//Main function for program
int main(int argc, char *argv[]) {
  if (argc != 2) {
    usage();
  }

  int freq[256] = {0};  // array initialized to 0

  std::ifstream fin(argv[1]);
  if (fin.is_open()) {
    char ch;
    while (fin >> std::noskipws >> ch) {  // don't skip whitespace
      if (ch != '\n') 
        freq[(int) ch]++; 
    }

    fin.close();
  }

  //Create a new priority queue 
  p_queue* q = new p_queue();
  
  //Load the priority queue with all relevant characters and their 
  //associated frequencies within the provided text
  for (int i = 0; i < 256; i++) {
    if (freq[i] != 0) 
      q->insert(new p_node(freq[i], i)); //Insert the new node into the p_queue
  }
  
  //Create the code tree for the provided text using the recently created 
  //priority queue
  CodeTree codeTree = CodeTree(q);

  //Now, print out the results of the Huffman coding the given input
  codeTree.printTree();
  codeTree.printCode();

  return 0;
}
