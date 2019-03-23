#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int comparisons = 0;

inline void printArray(int *array, int size) {
    cout<<"{ ";
    for(int i=0; i<size; i++ ) 
        cout<<array[i]<<' ';
    cout<<"}"<<endl;
}

inline void swap(int& a,int& b) {
    int c = a;
    a = b;
    b = c;
}

int partition(int* array, int start, int end) {
    int pivotElement = array[end];
    int i = start-1;
    for(int j=start; j<end; j++) {
        if(array[j] <= pivotElement) {
            i++;
            comparisons+=2;
            swap(array[i], array[j]);
        }
    }
    swap(array[i+1],array[end]);
    return i+1;
}

int randomizedPartition(int* array, int start, int end) {
    int randomPivotIndex = (rand()%(end-start)) + start;
    swap(array[end], array[randomPivotIndex]);
    return partition(array, start, end);
}


void randomizedQuickSort(int* array, int start, int end) {
    if(start<end) {
        comparisons++;
        int pivotIndex = randomizedPartition(array, start, end);
        randomizedQuickSort(array, start, pivotIndex-1);
        randomizedQuickSort(array, pivotIndex+1, end);
    }
}

int main() {
    int size;
    int *array;
    cout<<"Enter size of array: ";
    cin>>size;
    array = new int[size];
    cout<<"Enter array elements separated by space: ";
    for(int i=0; i<size; i++) {
        cin>>array[i];
    }
    randomizedQuickSort(array, 0, size-1);
    cout<<"Number of comparisons: "<<comparisons<<endl;
    printArray(array, size);
    return 0;
}