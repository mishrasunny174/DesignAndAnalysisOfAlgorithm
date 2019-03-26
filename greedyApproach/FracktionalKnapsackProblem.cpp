#include <iostream>
#include <vector>

using namespace std;

void printKnapsack(int* profit, int* weight, float* knapsack, int totalItems) {
    int totalProfit = 0;
    cout<<"ITEM NUMBER\t\tINCLUDED?"<<endl;
    for(int i=0; i<totalItems; i++) {
        cout<<i<<"\t\t\t"<<knapsack[i]<<endl;
        if(knapsack[i]==1) 
            totalProfit += profit[i];
        else
            totalProfit += knapsack[i] * profit[i]; 
        
    }
    cout<<"\nTotal Profit: "<<totalProfit<<endl;

}

void fractionalKnapSackGreedyAboutWeight(int* profit, int* weight, int totalItems, int maximumWeight) {
    float *knapsack = new float[totalItems];
    for(int i=0; i<totalItems; i++) {
        knapsack[i] = 0;
    }
    int currentCapacityOfKnapsack = maximumWeight;
    for(int i=0; i<totalItems; i++) {
        if(weight[i] > currentCapacityOfKnapsack ) {
            knapsack[i] = float(currentCapacityOfKnapsack)/weight[i];
            break;
        } else {
            knapsack[i] = 1;
            currentCapacityOfKnapsack -= weight[i];
        }
    }
    printKnapsack(profit, weight, knapsack, totalItems);
    delete[] knapsack;
}

int main(int argc, char** argv) {
    int profits[] = {25, 24, 15};
    int weights[] = {18, 15, 10};
    fractionalKnapSackGreedyAboutWeight(profits, weights, 3, 20);
    return 0;
}