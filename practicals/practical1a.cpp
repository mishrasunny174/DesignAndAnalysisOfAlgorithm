#include<iostream>

using namespace std;

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
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    cout<<"No of comparisons: "<<insertionSort(array, 10)<<endl;
    for(int i=0;i<10;i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}