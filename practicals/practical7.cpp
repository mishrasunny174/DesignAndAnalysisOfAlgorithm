#include <iostream>
#include <queue>

using namespace std;

class graph{
    int numOfVertices;
    int** matrix;
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
    void bfs();
};

int main() {
    int numOfVertices;
    graph *g;
    cout<<"Enter num of vertices: ";
    cin>>numOfVertices;
    g = new graph(numOfVertices);
    g->bfs();
    return 0;
}

void graph::bfs() {
    bool *visited = new bool[numOfVertices];
    queue<int> q;
    int front = 0, rear=0;
    int startingVertex;
    cout<<"enter starting vertex(1-"<<numOfVertices<<"): ";
    cin >>startingVertex;
    q.push(startingVertex-1);
    visited[startingVertex-1] = true;
    cout<<"DFS traversal is: ";
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        cout<<current+1<<" ";
        for(int i=0;i<numOfVertices; i++) {
            if(matrix[current][i]>0 && !visited[i]) {
                q.push(i);
                visited[i] = true; 
            }
        }
    }
    cout<<endl;
}