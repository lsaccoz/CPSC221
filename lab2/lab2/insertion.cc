#include <iostream>
#include <cstdlib>
#include "insertion.h"

using namespace std;

// insertion sort with several errors

// store command-line arguments in x[] array 
void getArgs( int argc, char **argv ) {
  x_size = argc - 1;
  for( int i = 0; i < x_size; i++ )
    x[i] = atoi( argv[ i+1 ] );
}

void scootOver( int j ) {
  int k;
  for( k = y_size; k > j; k-- )
    y[k] = y[ k-1 ];
}

void insert( int xx ) {
  int j;

  if( y_size == 0 ) {
    y[0] = xx;
    return;
  }
  // Need to insert just before the first y element that xx is less than
  for( j=0; j< y_size; j++ ) {
    if( xx < y[j] ) {
      // shift y[j], y[j+1], ... rightward before inserting xx
      scootOver( j );
      y[j] = xx;
      return;
    }
  }
  y[y_size] = xx;
}

void processData() {
  for( y_size = 0; y_size < x_size; y_size++ ) 
    // insert x value in the proper place among y[0],....,y[y_size-1]
    insert( x[ y_size ] );
}

void printResults() {
  for( int i=0; i<x_size; i++ )
    cout << y[i] << " ";
  cout << endl;
}

int main( int argc, char ** argv ) {
  getArgs( argc, argv );
  processData();
  printResults();
}
