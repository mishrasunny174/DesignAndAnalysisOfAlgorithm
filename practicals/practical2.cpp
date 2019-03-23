#include <iostream>

using namespace std;

int comparisons = 0;

inline void printArray(int *array, int size) {
    cout<<"{ ";
    for(int i=0; i<size; i++ ) 
        cout<<array[i]<<' ';
    cout<<"}"<<endl;
}

inline int leftChild(int index) {
    return index*2+1;
}

inline int rightChild(int index) {
    return index*2+2;
}

inline void swap(int* array, int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void maxHeapify(int* array, int index, int size) {
    int left = leftChild(index);
    int right = rightChild(index);
    int largest = index;
    if(left < size && array[left] > array[largest]) {
        largest = left;
        comparisons+=2;
    }
    if(right < size && array[right] > array[largest]) {
        largest = right;
        comparisons+=2;
    }
    if(largest != index) {
        comparisons++;
        swap(array, largest, index);
        maxHeapify(array, largest, size);
    }
}

void buildMaxHeap(int* array, int size) {
    for(int i=(size/2)-1; i>=0; i--) {
        maxHeapify(array,i,size);
        comparisons++;
    }
}

void heapSort(int* array, int size) {
    buildMaxHeap(array, size);
    int heapSize = size;
    for(int i=size-1; i>=0; i--) {
        swap(array, 0, i);
        heapSize--;
        comparisons++;
        maxHeapify(array,0,heapSize);
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
    heapSort(array, size);
    cout<<"Number of comparisons: "<<comparisons<<endl;
    printArray(array, size);
    return 0;
}