#include <iostream>
#include <fstream>
#include <sstream>
#include <string>       // provides string class
#include <cctype>       // provides isalpha() and tolower()
#include <vector>



using namespace std;
//
//// o=o=o=o=o=o=o=o=o=o=o=o=o=o <index properties> o=o=o=o=o=o=o=o=o=o=o=o=o=o //
//struct Word
//{
//	string word;      // the actual word
//	vector<long> pgs; // pages that the word appears in
//	long occ;         // number of occurences of word
//
//	Word(string word_, vector<long> pgs_, long occ_)
//		: word(word_), pgs(pgs_), occ(occ_) {}
//};
//
//long lppg = 40; // lines per page
//vector<Word> index;
//
///**
//* helper function for binary search
//*/
//int find(string word, int l, int r)
//{
//	if (l > r) return -1;
//	int m = l + (r - l) / 2;
//	string m_word = index[m].word;
//	if (word == m_word)
//		return m;
//	else if (m_word.compare(word) == 1)
//		return find(word, l, m - 1);
//	else
//		return find(word, m + 1, r);
//}
//
///**
//* DELIVERABLE
//*/
//int find(string word)
//{
//	/* linear search
//	for (int i = 0; i < index.size(); i++)
//	if (index[i].word == word)
//	return i;
//	return -1;
//	*/
//
//	// binary search
//	if (index.empty()) return -1;
//	return find(word, 0, index.size() - 1);
//}
//
///**
//* DELIVERABLE
//*/
//void insert(string word, long pg)
//{
//	if (index.empty())
//	{
//		Word word_(word, { pg }, 1);
//		index.push_back(word_);
//		return;
//	}
//	int ii = find(word);
//	if (ii == -1)
//	{
//		Word Word_(word, { pg }, 1);
//		vector<Word>::iterator it;
//		for (it = index.begin(); it < index.end(); it++)
//			if (it->word.compare(word) == 1)  // if word in index is bigger
//				break;
//		index.insert(it, Word_);
//
//		/*
//		int N = index.size();
//		int guess = word[0] - 96; // ascii to [1,26]
//		it = index.begin() + (N > 26 ? guess*(N-1)/26 : 0);
//
//		if (it->word.compare(word) == 1) // less_than : if the word in index is bigger
//		while (it >= index.begin())
//		// implement
//		// loop until word is less than word in the index
//		if (it->word.compare(word) == -1) // it->word < word
//		break;
//		else if ((it-1) >= index.begin())
//		it = it - 1;
//		else break;
//		else
//		while (it <= index.end())
//		// implement
//		// loop until word is more than word in the index
//		if (word.compare(it->word) == -1)
//		break;
//		else if ((it+1) <= index.end())
//		it = it + 1;
//		else break;
//		index.insert(it, Word_);
//		*/
//
//		/*
//		int N = index.size();
//		int guess = word[0] - 96;
//		int i = guess*(N - 1) / 26;
//
//		int i_ret;
//
//		if (index[i].word.compare(word) == 1) // if the word in index is bigger
//		{
//		i_ret = 0;
//		while (i >= 0)
//		// implement
//		// loop until word is less than word in the index
//		if (word.compare(index[i].word) == 1) {
//		i_ret = i + 1;
//		break;
//		}
//		else if ((i - 1) >= 0)
//		i = i - 1;
//		else break;
//		}
//		else
//		{
//		i_ret = N - 1;
//		while (i < N)
//		// implement
//		// loop until word is more than word in the index
//		if (index[i].word.compare(word) == 1) {
//		i_ret = i;
//		break;
//		}
//		else if ((i + 1) < N)
//		i = i + 1;
//		else break;
//		}
//		index.insert(index.begin() + i_ret, Word_);
//		*/
//	}
//	else
//	{
//		index[ii].occ++;
//		if (pg != index[ii].pgs[index[ii].pgs.size() - 1])
//			index[ii].pgs.push_back(pg);
//	}
//}
//
///**
//* Helper function
//*/
//void print_pages(vector<long> x, ostream &output)
//{
//	if (x.empty()) { output << endl; return; }
//	if (x.size() == 1) { output << x[0] << endl; return; }
//	long beg = 0;
//	long end = 0;
//	for (int p = 0; p < x.size() - 1; p++)
//	{
//		if (x[p] + 1 == x[p + 1]) end++;
//		else
//		{
//			if (beg == end) output << x[beg] << ",";
//			else output << x[beg] << "-" << x[end] << ",";
//			beg = ++end;
//		}
//	}
//	if (beg == end) output << x[beg] << endl;
//	else output << x[beg] << "-" << x[end] << endl;
//}
//
///**
//* DELIVERABLE
//*/
//void printInOrder(ostream &output)
//{
//	for (int i = 0; i < index.size(); i++)
//	{
//		Word Word_ = index[i];
//		output << Word_.word << " (" << Word_.occ << ") ";
//		print_pages(Word_.pgs, output);
//	}
//}
//
//
//// o=o=o=o=o=o=o=o=o=o=o=o=o=o <\index properties> o=o=o=o=o=o=o=o=o=o=o=o=o=o //
//
//// The following function should be moved into your skiplist.cc file when you
//// write that.  It implements the random bit generation.
//#include <ctime>                // for time()
//#include <cstdlib>              // for rand(), srand(), and RAND_MAX
//
//int randBit(void) {             // return a "random" bit
//	static int bitsUpperBd = 0;
//	static int bits;              // store bits returned by rand()
//	if (bitsUpperBd == 0) {      // refresh store when empty
//		bitsUpperBd = RAND_MAX;
//		bits = rand();
//	}
//	int b = bits & 1;
//	bits >>= 1;
//	bitsUpperBd >>= 1;
//	return b;
//}
//
//
//// Remove all characters except letters (A-Z,a-z) from line,
//// except keep '-' or '\'' if they are between letters.
//void lowercaseWords(string & line) {
//	for (string::iterator it = line.begin(); it != line.end(); ++it) {
//		if (!isalpha(*it)) {
//			if ((*it != '-' && *it != '\'') ||
//				it == line.begin() || it + 1 == line.end() ||
//				!isalpha(*(it - 1)) || !isalpha(*(it + 1))) {
//				*it = ' ';
//			}
//		}
//		else {
//			*it = tolower(*it);
//		}
//	}
//}
//
//void print(ostream & output, string & word) {
//	output << word << endl;
//}
//
//int main(int argc, char *argv[]) {
//	if (argc != 3)
//	{
//		cerr << "Usage: " << argv[0] << " book.txt index.txt" << endl;
//		exit(1);
//	}
//
//	ifstream fin;
//	fin.open(argv[1]);
//	if (!fin.is_open())
//	{
//		cerr << "Unable to open " << argv[1] << endl;
//		exit(2);
//	}
//
//	ofstream fout;
//	fout.open(argv[2]);
//	if (!fout.is_open())
//	{
//		cerr << "Unable to open " << argv[2] << endl;
//		exit(3);
//	}
//
//	string line, word;
//	long pg = 0, line_num = 0;
//	while (!fin.eof())
//	{
//		getline(fin, line);
//		lowercaseWords(line);
//		if (line_num == 0) pg++;
//		line_num = (line_num + 1) % lppg;
//		istringstream iss(line, istringstream::in);
//		while (iss >> word)
//		{
//			//print(fout, word);
//			insert(word, pg);
//		}
//	}
//	printInOrder(fout);
//
//}

int UCP(string &s, int n, int num_opened)
{
	if (n >= s.size()) return 0;
	if (s[n] == `('))  return UCP(s, n+1, num_opened+1);
		bool c = s[n] == `)';
		if (num_opened > 0)
			return UCP(s, n + 1, num_opened - (c ? 1 : 0));
		else
			return (c ? 1 : 0) + UCP(s, n + 1, num_opened);
}

int unmatchedClosingParenthesis(String &s)
{
	return UCP(s, 0, 0);
}

int main()
{
	int x1 = unmatchedClosingParenthesis("(hello(world)) ()) (oops!))");
	int x2 = unmatchedClosingParenthesis(") totally unmatched (");

	cout << x1 << endl;
	cout << x2 << endl;

	while (true);
}