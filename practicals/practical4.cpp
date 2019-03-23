#include <iostream>

using namespace std;

inline void printArray(int* array, int size) {
    cout<<"{ ";
    for(int i=0; i<size; i++) {
        cout<<array[i]<<" ";
    }
    cout<<"}"<<endl;
}

int getMax(int *array, int size) {
    int max = array[0];
    for(int i=1; i<size; i++)
        if(max<array[i])
            max = array[i];
    return max;
}

void countSort(int* array, int size, int exp) {
    int count[10] = {0};
    int *output = new int[size];
    for(int i=0; i<size; i++)
        count[int(array[i]/exp)%10]++;
    for(int i=1; i<10; i++) {
        count[i] += count[i-1];
    }
    for(int i=0; i<size; i++) {
        output[count[int(array[i]/exp)%10] - 1] = array[i];
        count[int(array[i]/exp)%10]--;
    }
    for(int i=0; i<size; i++) {
        array[i] = output[i];
    }
}

void radixSort(int* array, int size) {
    int max = getMax(array, size);
    for(int exp=1; max/exp>0; exp*=10) {
        countSort(array, size, exp);
    }
}

int main(int argc, char**argv) {
    int size;
    int *array;
    cout<<"Enter size of array: ";
    cin>>size;
    array = new int[size];
    cout<<"Enter array elements separated by space: ";
    for(int i=0; i<size; i++) {
        cin>>array[i];
    }
    radixSort(array, size);
    printArray(array, size);
    return 0;
}