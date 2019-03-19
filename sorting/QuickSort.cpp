#include <iostream>

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

void quickSort(int* array, int start, int end) {
    if(start<end) {
        int pivotIndex = partition(array, start, end);
        quickSort(array, start, pivotIndex-1);
        quickSort(array, pivotIndex+1, end);
    }
}

int main() {
    int array[] = {9,8,7,6,5,4,3,2,1};
    quickSort(array, 0, 8);
    for(int i=0; i<9; i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}