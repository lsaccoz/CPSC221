#include <iostream>
#include <fstream>
#include <sstream>
#include <string>       // provides string class
#include <cctype>       // provides isalpha() and tolower()
#include <vector>


using namespace std;

// ---------------------------- <index properties> ------------------------- //
struct Word
{
	string word;      // the actual word
	vector<long> pgs; // pages that the word appears in
	long occ;         // number of occurences of word
};

long lppg = 40; // lines per page
vector<Word> index;

/**
* helper function for binary search
*/
int find(string word, int l, int r)
{
	if (l > r) return -1;
	int m = l + (r - l) / 2;
	string m_word = index[m].word;
	if (word == m_word)
		return m;
	else if (m_word.compare(word) > 0)
		return find(word, l, m - 1);
	else
		return find(word, m + 1, r);
}

/**
* DELIVERABLE
*/
int find(string word)
{
	// binary search
	if (index.empty()) return -1;
	return find(word, 0, index.size() - 1);
}

/**
* DELIVERABLE
*/
void insert(string word, long pg)
{
	if (index.empty())
	{
		vector<long> v; v.push_back(pg);
		Word word_;
		word_.word = word;
		word_.pgs = v;
		word_.occ = 1;
		index.push_back(word_);
		return;
	}
	int ii = find(word);
	if (ii == -1)
	{
		vector<long> v; v.push_back(pg);
		Word Word_;
		Word_.word = word;
		Word_.pgs = v;
		Word_.occ = 1;
		vector<Word>::iterator it;
		for (it = index.begin(); it < index.end(); it++)
			if (it->word.compare(word) > 0)  // if word in index is bigger
				break;
		index.insert(it, Word_);
	}
	else
	{
		index[ii].occ++;
		if (pg != index[ii].pgs[index[ii].pgs.size() - 1])
			index[ii].pgs.push_back(pg);
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
	for (int i = 0; i < index.size(); i++)
	{
		Word Word_ = index[i];
		output << Word_.word << " (" << Word_.occ << ") ";
		print_pages(Word_.pgs, output);
	}
}


// ------------------------ <\index properties> --------------------------- //

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
			//print(fout, word);
			insert(word, pg);
		}
	}
	printInOrder(fout);

}
