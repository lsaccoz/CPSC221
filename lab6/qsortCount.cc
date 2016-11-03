#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define NOT_FOUND -1

int NN = 1000;
int REP =  100;

int * x;
int comps;
int *C;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		comps++;
		if (x[i] < x[a])
			swap(x[++m], x[i]);
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

int qc(int n) {
	if (n <= 1) return 0;
	int p = randint(0, n);
	return n-1 + qc(p-1) + qc(n-p);
}

float c(int n) {
	if (n <= 1) return 0;
	float sum = 0.0;
	for (int m = 1; m <= n; m++) {
		sum += n-1;
		if (C[m-1] == NOT_FOUND) C[m-1] = c(m-1);
		sum += C[m-1];
		if (C[n-m] == NOT_FOUND) C[n-m] = c(n-m);
		sum += C[n-m];
	}
	return sum / n;
}

int main(int argc, char *argv[]) {
	srand(time(0));
	float comps_avg = 0;

	x = new int[NN];
	for (int rep = 0; rep < REP; rep++) {
		comps = 0;
		for (int i=0; i<NN; ++i) {
			x[i] = rand() % NN;
		}
		quicksort(0, NN-1);
		comps_avg += 1.0*comps / REP;
	}

	C = new int[NN];
	for (int i = 0; i < NN; i++) C[i] = NOT_FOUND;

	comps = 0;
	
	cout << "Average number of comparisons for array size "
	     << NN << " for " << REP << " repetitions: " << comps_avg << endl << endl;
    
	cout << "The number of comparisons increases as NN increases." << endl;
	//cout << "The average number of comparisons seems to be close to NN*log2(NN)" << endl << endl;
		 
	cout << "qc(" << NN <<") = " << qc(NN) << endl;

	cout << "c(" << NN << ")  = " << c(NN) << endl;
	
	cout << endl;

	delete[] x;
    
	return 0;
}
