#include<iostream>

using namespace std;

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

inline void printArray(int* array, int size) {
    for(int i=0; i<10; i++) {
        cout << array[i] << " ";
    }
    cout<<endl;
}

void maxHeapify(int* array, int index, int size) {
    int left = leftChild(index);
    int right = rightChild(index);
    int largest = index;
    if(left < size && array[left] > array[largest]) {
        largest = left;
    }
    if(right < size && array[right] > array[largest]) {
        largest = right;
    }
    if(largest != index) {
        swap(array, largest, index);
        maxHeapify(array, largest, size);
    }
}

void buildMaxHeap(int* array, int size) {
    for(int i=(size/2)-1; i>=0; i--) {
        maxHeapify(array,i,size);
    }
}

void heapSort(int* array, int size) {
    buildMaxHeap(array, size);
    int heapSize = size;
    for(int i=size-1; i>=0; i--) {
        swap(array, 0, i);
        heapSize--;
        maxHeapify(array,0,heapSize);
    }
}

int main(int argc, char** argv) {
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    heapSort(array, 10);
    printArray(array, 10);
}