#include <iostream>
#include <fstream>
#include <time.h>

#include <stdlib.h>
using namespace std;

#define MAX 500000

double a[MAX];

void Q_Sort(int left, int right){
	if (left>=right) return;
	double pivot= a[left + (right - left)/2];
	int i = left, j = right;
	while(i<=j){
		while (a[i]<pivot) i++;
		while (a[j]>pivot) j--;
		//cout<<i<<" "<<j<<endl;
		if (i<=j){
			swap(a[i], a[j]);
			i++, j--;
		};
	};
	if (i<right) Q_Sort(i,right);
	if (j>left) Q_Sort(left,j);
};
///

int main(){
    double  time[10];
    ofstream outf("result_QS.txt");
    for (int i=0; i < 10; i++){
    		clock_t start, end;   
        double time_use; 
    	char name[1];
		itoa(i,name,10);
		ifstream inf(name);
		for (int j = 0; j<MAX; j++) inf>>a[j];
		start = clock(); 
    	Q_Sort(0, MAX-1);
    	end = clock();
    	//quickSort(a, 0, MAX- 1);
    	time_use = (double)(end - start) ; 
    	outf<<time_use*10<<endl;
    	inf.close();
	};
	outf.close();
    return 0;
}
