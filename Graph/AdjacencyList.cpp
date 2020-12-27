/*
    
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    int count = 0;
    int vertices;
    vector<int>* v;
    vector<bool>* visited;
    public:
    Graph(int n){
        v = new vector<int>[n];
        vertices = n;
        visited = new vector<bool>(n,false);
    }
    void addEdge(int x,int y){
        v[x].push_back(y);
        v[y].push_back(x);
    }
    void printGraph(){
        for(int i = 0; i < vertices; i++ ){
            cout << i <<"->" ;
            for(auto x : v[i]){
                if(++count == 1)
                    cout << x;
                else 
                    cout << "-->" << x;
            }
            count = 0;
            cout << endl;
        }
    }
    // void BFS(int x){
    //     vector<bool> visited(vertices,false);
    //     queue<int> q;
    //     q.push(x);
    //     visited[x] = true;
    //     while(!q.empty()){
    //         int front = q.front();
    //         cout << front << " ";
    //         q.pop();
    //         for(auto n : v[front]){
    //             if(!visited[n]){
    //                 q.push(n);
    //                 visited[n] = true;
    //             }
    //         }
    //     }
    // }
    void DFS(int x){
        visited->at(x) = true;
        cout << x << " ";
        for(auto n : v[x]){
            if(!visited->at(n))
                DFS(n);
        }
    }
};
int main(){

    Graph g(4);

    // g.addEdge(0,1);
    // g.addEdge(0,2);
    // g.addEdge(1,3);
    // g.addEdge(2,3);
    // g.addEdge(2,4);
    // g.addEdge(3,5);
    // g.addEdge(5,4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

    g.printGraph();

    //g.BFS(2);
    g.DFS(3);

} 