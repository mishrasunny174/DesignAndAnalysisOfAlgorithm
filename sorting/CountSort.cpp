#include <iostream>

using namespace std;

inline void printArray(int *array, int size) {
    cout<<"{ ";
    for(int i=0; i<size; i++) {
        cout<<array[i]<<" ";
    }
    cout<<"}"<<endl;
}

void countSort(int* array, int size, int range) {
    int* countArray = new int[range+1];
    int* tempArray = new int[size];
    for(int i=0; i<=range; i++) {
        countArray[i] = 0;
    }

    for(int i=0; i<size; i++) {
        countArray[array[i]] += 1;
    }

    for(int i=1; i<=range; i++) {
        countArray[i] = countArray[i-1]+1;
    }

    for(int i=0; i<size; i++) {
        tempArray[countArray[array[i]]-1] = array[i];
        countArray[array[i]]--;
    }


    for(int i=0; i<size; i++) {
        array[i] = tempArray[i];
    }
    delete[] tempArray;
    delete[] countArray;
}

int main(int argc, char* argv[]) {
    int array[] = {9,8,7,6,5,4,3,2,1,0};
    printArray(array, 10);
    countSort(array, 10, 10);
    printArray(array, 10);
    return 0;
}