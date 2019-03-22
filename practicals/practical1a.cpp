#include<iostream>

using namespace std;

inline void printArray(int *array, int size) {
    cout<<"{ ";
    for(int i=0; i<size; i++ ) 
        cout<<array[i]<<' ';
    cout<<"}"<<endl;
}

int insertionSort(int* array, int size) {
    int comparisons = 0;
    int current,j;
    for(int i=0; i<size; i++) {
        comparisons += 1;
        current = array[i];
        j = i-1;
        while(j>=0 && array[j] > current) {
            array[j+1] = array[j];
            comparisons += 2;
            j--;
        }
        array[j+1] = current;
    }
    return comparisons;
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
    cout<<"Number of comparisons: "<<insertionSort(array, size)<<endl;
    printArray(array, size);
    return 0;
}