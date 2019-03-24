#include <iostream>
#include <climits>

using namespace std;

int fibonacciRecursive(int n) {
    if(n<2) {
        return n;
    }
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

int fibonacciMemoizedSub(int n, int* results) {
    if(results[n] == INT32_MIN) {
        if(n<2) {
            results[n] = n;
        } else {
            results[n] = fibonacciMemoizedSub(n-1, results) + fibonacciMemoizedSub(n-2, results);
        }
    }
    return results[n];
} 

int fibonacciMemoized(int n) {
    int *results = new int[n+1];
    int retValue;
    for(int i=0; i<=n; i++) {
        results[i] = INT32_MIN;
    }
    retValue =  fibonacciMemoizedSub(n, results);
    delete[] results;
    return retValue;
}

int fibonacciTabulized(int n) {
    if(n>1) {

        int *results = new int[n+1];
        int retValue;
        results[0] = 0;
        results[1] = 1;
        for(int i=2; i<=n; i++) {
            results[i] = results[i-1] + results[i-2];
        }
        retValue = results[n];
        delete[] results;
        return retValue;
    }
    return n;
}

int main(int argc, char** argv) {
    cout<<"Recursive: "<<fibonacciMemoized(45)<<endl;
    cout<<"Tabulized: "<<fibonacciTabulized(45)<<endl;
    cout<<"Memoized: "<<fibonacciRecursive(45)<<endl;
    return 0;
}