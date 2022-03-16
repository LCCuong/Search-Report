#include <iostream>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

#define MAX 500000

double a[MAX];


int main(){
    double  time[10];
    ofstream outf("result_sysS.txt");
    for (int i=0; i < 10; i++){
    	clock_t start, end;   
        double time_use; 
    	char name[1];
		itoa(i,name,10);
		ifstream inf(name);
		for (int j = 0; j<MAX; j++) inf>>a[j];
		start = clock();
    	sort(a, a+MAX);
    	end = clock();
    	time_use = (double)(end - start) ;
    	outf<<time_use*10<<endl;
    	inf.close();
	};
	outf.close();
    return 0;
}
