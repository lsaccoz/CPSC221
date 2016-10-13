#include <iostream>
#include <fstream>
#include <sstream>
#include <string>       // provides string class
#include <cctype>       // provides isalpha() and tolower()
#include <vector>


using namespace std;

// The following function should be moved into your skiplist.cc file when you
// write that.  It implements the random bit generation.
#include <ctime>                // for time()
#include <cstdlib>              // for rand(), srand(), and RAND_MAX

int randBit(void) {             // return a "random" bit
	static int bitsUpperBd = 0;
	static int bits;              // store bits returned by rand()
	if (bitsUpperBd == 0) {      // refresh store when empty
		bitsUpperBd = RAND_MAX;
		bits = rand();
	}
	int b = bits & 1;
	bits >>= 1;
	bitsUpperBd >>= 1;
	return b;
}

// ---------------------------- <index properties> ------------------------- //
long lppg = 40; // lines per page
int MAX_HEIGHT = 16;

struct Word
{
	string word;      // the actual word
	vector<long> pgs; // pages that the word appears in
	long occ;         // number of occurences of word
};

struct Node
{
	Word* word_data;
	Node** next;
	int height;
};

Node* createNode(int h)
{
	Node *node = new Node();
	node->next = new Node*[MAX_HEIGHT];
	for (int i = 0; i < MAX_HEIGHT; i++)
		node->next[i] = NULL;
	node->height = h;
	node->word_data = NULL;
	return node;
}

Node* createNode(Word* word_, int h)
{
	Node* node = createNode(h);
	node->word_data = word_;
	return node;
}

Word* createWord(string wrd, long pg)
{
	vector<long> v; v.push_back(pg);
	Word* word_ = new Word();
	word_->word = wrd;
	word_->pgs = v;
	word_->occ = 1;
	return word_;
}

Node* head; // the index head dummy node
Node** update; // which node to update

int randHeight()
{
	int i;
	for (i = 1; i < MAX_HEIGHT; i++)
		if (randBit() == 1) break;
	return i;
}

/**
* DELIVERABLE
*/
Node* find(string word)
{
	Node* node = head;
	for (int h = MAX_HEIGHT - 1; h >= 0; h--)
	{
		while (node->next[h] != NULL && node->next[h]->word_data->word.compare(word) < 0)
		{
			update[h] = node;
			node = node->next[h];
		}
		update[h] = node;
		if (node->next[h] != NULL && node->next[h]->word_data->word.compare(word) == 0)
			return node->next[h];
	}
	return NULL;
}

/**
* DELIVERABLE
*/
void insert(string word, long pg)
{
	if (head->next[0] == NULL)
	{
		Word* word_ = createWord(word, pg);
		Node* x = createNode(word_, randHeight());
		for (int i = 0; i < x->height; i++)
			head->next[i] = x;
		return;
	}
	Node* found = find(word);
	if (found == NULL)
	{
		Word* word_ = createWord(word, pg);
		Node* x = createNode(word_, randHeight());
		for (int h = 0; h < x->height; h++)
		{
			x->next[h] = update[h]->next[h];
			update[h]->next[h] = x;
		}
	}
	else
	{
		found->word_data->occ++;
		if (pg != found->word_data->pgs[found->word_data->pgs.size() - 1])
			found->word_data->pgs.push_back(pg);
	}
}

/**
* Helper function
*/
void print_pages(vector<long> x, ostream &output)
{
	if (x.empty()) { output << endl; return; }
	if (x.size() == 1) { output << x[0] << endl; return; }
	long beg = 0;
	long end = 0;
	for (int p = 0; p < x.size() - 1; p++)
	{
		if (x[p] + 1 == x[p + 1]) end++;
		else
		{
			if (beg == end) output << x[beg] << ",";
			else output << x[beg] << "-" << x[end] << ",";
			beg = ++end;
		}
	}
	if (beg == end) output << x[beg] << endl;
	else output << x[beg] << "-" << x[end] << endl;
}

/**
* DELIVERABLE
*/
void printInOrder(ostream &output)
{
	Node* node = head;
	while ( (node = node->next[0]) != NULL )
	{
		Word *word_ = node->word_data;
		output << word_->word << " (" << word_->occ << ") ";
		print_pages(word_->pgs, output);
	}
}


// ------------------------ <\index properties> --------------------------- //

// Remove all characters except letters (A-Z,a-z) from line,
// except keep '-' or '\'' if they are between letters.
void lowercaseWords(string & line) {
	for (string::iterator it = line.begin(); it != line.end(); ++it) {
		if (!isalpha(*it)) {
			if ((*it != '-' && *it != '\'') ||
				it == line.begin() || it + 1 == line.end() ||
				!isalpha(*(it - 1)) || !isalpha(*(it + 1))) {
				*it = ' ';
			}
		}
		else {
			*it = tolower(*it);
		}
	}
}

void print(ostream & output, string & word) {
	output << word << endl;
}

int main(int argc, char *argv[]) {
	if (argc != 3)
	{
		cerr << "Usage: " << argv[0] << " book.txt index.txt" << endl;
		exit(1);
	}

	ifstream fin;
	fin.open(argv[1]);
	if (!fin.is_open())
	{
		cerr << "Unable to open " << argv[1] << endl;
		exit(2);
	}

	ofstream fout;
	fout.open(argv[2]);
	if (!fout.is_open())
	{
		cerr << "Unable to open " << argv[2] << endl;
		exit(3);
	}

	srand(time(0));
	head = createNode(MAX_HEIGHT);
	update = new Node*[MAX_HEIGHT];

	string line, word;
	long pg = 0, line_num = 0;
	while (!fin.eof())
	{
		getline(fin, line);
		lowercaseWords(line);
		if (line_num == 0) pg++;
		line_num = (line_num + 1) % lppg;
		istringstream iss(line, istringstream::in);
		while (iss >> word)
		{
			insert(word, pg);
		}
	}
	printInOrder(fout);

}
