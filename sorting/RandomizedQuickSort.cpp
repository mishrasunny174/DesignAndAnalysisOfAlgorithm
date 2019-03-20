#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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
            swap(array[i], array[j]);
        }
    }
    swap(array[i+1],array[end]);
    return i+1;
}

int randomizedPartition(int* array, int start, int end) {
    int randomPivotIndex = (rand()%end) + start;
    swap(array[end], array[randomPivotIndex]);
    return partition(array, start, end);
}


void randomizedQuickSort(int* array, int start, int end) {
    if(start<end) {
        int pivotIndex = randomizedPartition(array, start, end);
        randomizedQuickSort(array, start, pivotIndex-1);
        randomizedQuickSort(array, pivotIndex+1, end);
    }
}

int main() {
    int array[] = {9,8,7,6,5,4,3,2,1};
    randomizedQuickSort(array, 0, 8);
    for(int i=0; i<9; i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}