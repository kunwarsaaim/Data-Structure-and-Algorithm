//
//  main.cpp
//  DFS_BFS
//
//  Created by Kunwar Rehan on 16/10/19.
//  Copyright © 2019 Kunwar Saaim. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

class Graph{
    int v;
    list<int> *adj;
public:
    Graph(int v);
    
    void addEdge(int v,int w);
    
    void bfs(int s);
    void dfs(int s);
};

Graph::Graph(int V){
    v = V;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::bfs(int s){
    bool *visited = new bool[v];
    for (int i=0; i<v; i++) {
        visited[i] = false;
    }
    list<int> que;
    
    visited[s] = true;
    que.push_back(s);
    list<int> :: iterator i;
    
    while (!que.empty()) {
        s = que.front();
        cout<<s<<" ";
        que.pop_front();
        
        for (i = adj[s].begin(); i!=adj[s].end(); i++) {
            if(!visited[*i]){
                visited[*i]=true;
                que.push_back(*i);
            }
        }
    }
}
void Graph::dfs(int s){
    bool *visited = new bool[v];
    
    for (int i=0; i<v; i++) {
        visited[i] = false;
    }
    list<int> stack;
    
    
    stack.push_back(s);
    visited[s] = true;
    list<int> :: iterator i;
    while (!stack.empty()) {
        s = stack.back();
        stack.pop_back();
        cout<<s<<" ";

        for (i = adj[s].begin(); i!=adj[s].end(); i++) {
            if (!visited[*i]) {
                stack.push_back(*i);
                visited[*i]=true;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "Following is Breadth First Traversal "
           << "(starting from vertex 2) \n";
      g.dfs(2);
    
    return 0;
}
