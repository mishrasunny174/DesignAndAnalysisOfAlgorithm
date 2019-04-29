#include <iostream>
#include <queue>

using namespace std;

class graph{
    int numOfVertices;
    int** matrix;
    bool *visited;
public:
    graph(int numOfVertices) {
        this->numOfVertices = numOfVertices;
        matrix = new int*[numOfVertices];
        for(int i=0; i < numOfVertices; i++) {
            matrix[i] = new int[numOfVertices];
        }
        cout<<"Enter graph matrix"<<endl;
        for(int i=0; i<numOfVertices; i++) {
            cout<<"Enter row # "<<i+1<<" : ";
            for(int j=0;j<numOfVertices; j++) 
                cin>>matrix[i][j];
        }
    }
    ~graph() {
        for(int i=0; i<numOfVertices; i++) 
            delete[] matrix[i];
        delete[] matrix;
    }
    void dfs();
    void dfs(int);
};

int main() {
    int numOfVertices;
    graph *g;
    cout<<"Enter num of vertices: ";
    cin>>numOfVertices;
    g = new graph(numOfVertices);
    g->dfs();
    return 0;
}

void graph::dfs() {
    visited = new bool[numOfVertices];
    int current;
    cout<<"Enter starting node(1-"<<numOfVertices<<"): ";
    cin>>current;
    current--;
    visited[current] = true;
    this->dfs(current);
    cout<<endl;
}

void graph::dfs(int current) {
    cout<<current+1<<" ";
    for(int i=0;i<numOfVertices;i++) {
        if(matrix[current][i]>0 && !visited[i]) {
            visited[i] = true;
            dfs(i);
        }
    }
}