#include <iostream>

using namespace std;

int comparisons = 0;

inline void printArray(int *array, int size) {
    cout<<"{ ";
    for(int i=0; i<size; i++ ) 
        cout<<array[i]<<' ';
    cout<<"}"<<endl;
}

void merge(int* array, int start, int mid, int end) {
    int size = end - start + 1;
    int *tempArray = new int[size];
    int counter1=start, counter2=mid+1, counter3=0;
    while(counter1<=mid && counter2<=end) {
        if(array[counter1] < array[counter2]) {
            tempArray[counter3++] = array[counter1++];
        } else {
            tempArray[counter3++] = array[counter2++];
        }
        comparisons+=1;
    }
    while(counter1<=mid) {
        comparisons+=1;
        tempArray[counter3++] = array[counter1++];
    }
    while(counter2<=end) {
        comparisons+=1;
        tempArray[counter3++] = array[counter2++];
    }
    for(int i=0; i<counter3; i++) {
        array[i+start] = tempArray[i];
    }
}

void mergeSort(int* array,int start, int end) {
    if (start < end) {
        comparisons+=1;
        int mid = (start+end)/2;
        mergeSort(array, start, mid);
        mergeSort(array, mid+1, end);
        merge(array, start, mid, end);
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
    mergeSort(array, 0, size-1);
    cout<<"Number of comparisons: "<<comparisons<<endl;
    printArray(array, size);
    return 0;
}