#include <iostream>
#include <fstream>
#include <sys/time.h>
#include<time.h>   

#include <stdlib.h>
using namespace std;

#define MAX 500000
int a[MAX];

void merge(int left1, int right1, int left2, int right2){
//	cout<<"lan chay:"<<left1<<"-"<<right2<<endl;
	int i1 = left1, i2= left2, temp_i = 0;
	//cout<<i1<<" "<<i2<<endl;
	//for (int i=0;i<=temp_i;i++) cout<<temp[i]<<" ";
	int range = right2-left1+1;
	int temp[range];
	//for (int i=0;i<=right2-left1+1; i++) temp[i] = 0;
	while (i1<=right1&&i2<=right2){
	//	cout<<a[i1]<<" "<<a[i2]<<endl;
		if (a[i1]<a[i2]){
			temp[temp_i] = a[i1];
	//		cout<<a[i1]<<" "<<temp[temp_i]<<endl;
			i1++;
			temp_i++;
		}else{
			temp[temp_i] = a[i2];
	//		cout<<a[i1]<<" "<<temp[temp_i]<<endl;
			i2++;
			temp_i++;
		};
	//	for (int i=0;i<=temp_i;i++) cout<<temp[i]<<" ";
	//	cout<<endl;
	};
	//cout<<temp_i<<endl;

	//cout<<endl;
	if (i1<=right1) for (int i=i1; i<=right1; i++){temp[temp_i] = a[i]; temp_i++;};
	if (i2<=right2) for (int i=i2; i<=right2; i++){temp[temp_i] = a[i]; temp_i++;};
	for (int i=left1; i<=right2; i++) a[i] = temp[i-left1];
		//for (int i=0;i<=temp_i;i++) cout<<temp[i]<<" ";
	//	cout<<endl;
	//	cout<<endl;
	return;
};

void merge_sort(int left, int right){
	if (right - left + 1 == 1) return;
	int mid = left + (right-left)/2;
	
	//cout<<endl;
	merge_sort(left, mid);
	merge_sort(mid+1, right);
	merge(left, mid, mid+1, right);
	
};


int main(){
    float  time[10];
    ofstream outf("result_MS.txt");
   for (int i=0; i < 10; i++){
   		clock_t start, end;   
        double time_use; 
    	char name[1];
		itoa(i,name,10);
		ifstream inf(name);
		for (int j = 0; j<MAX; j++) inf>>a[j];
		//struct timeval begin, end;
    	start = clock(); 
    	merge_sort(0, MAX-1);
    	//mergeSort(a,0, MAX-1);
    	//quickSort(a, 0, MAX- 1);
    	 end = clock();
    	//long seconds = end.tv_sec - begin.tv_sec;
    	time_use = (double)(end - start) ; 
    	outf<<time_use*10<<endl;
    	inf.close();
	};
	outf.close();
    return 0;
}
