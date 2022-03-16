#include <iostream>
#include <fstream>
#include <time.h>

#include <stdlib.h>
using namespace std;

#define MAX 500000
int a[MAX];

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
 
///

int main(){
    double  time[10];
    ofstream outf("result_HS.txt");
    for (int i=0; i < 10; i++){
    		clock_t start, end;   
        double time_use; 
    	char name[1];
		itoa(i,name,10);
		ifstream inf(name);
		for (int j = 0; j<MAX; j++) inf>>a[j];
		start = clock(); 
    	heapSort(a,MAX);
    	end = clock();
    	//quickSort(a, 0, MAX- 1);
    	time_use = (double)(end - start) ; 
    	outf<<time_use*10<<endl;
    	inf.close();
	};
	outf.close();
    return 0;
}
