#include <iostream>

using namespace std;

void selectActivities(int* startTime, int* endTime, int totalActivities) {
    int currentActivity = 0;
    cout<<"selected activities are: { "<<1<<" ";
    for(int i=1; i<totalActivities; i++) {
        if(startTime[i] >= endTime[currentActivity]) {
            cout<<i+1<<" ";
            currentActivity = i;
        }
    }
    cout<<"}"<<endl;
}

int main() {
    int startTimes[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int endTimes[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    selectActivities(startTimes, endTimes, 11);
    return 0;
}