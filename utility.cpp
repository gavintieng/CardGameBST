// Implementation of any other clases needed

#include "movies.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using std::cout;

double searchTime(MovieBST &test,MovieNode *n,int w){
	
	double total=0.0;

	for(int i=0;i<w;i++){

		clock_t start=clock();
		test.contains(n);
		}
		clock_t end=clock();
		total+=difftime(end,start);

		return total/w;

}



int main(){
	MovieBST test;
	
}