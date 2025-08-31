#include<bits/stdc++.h>
using namespace std;

// Check : 
// edges must be 1 less than total nodes.
// graph must not contain cycle.
// graph must have single component.

bool IsCyclic(unordered_map<int,vector<int>> & g , int curr, int parent , int & vis[ ]){
    vis[curr] = true;
    bool cycle = false;
    for(int next : g[curr]){
        if(vis[next] == false){
            cycle = IsCyclic(g , next , curr);
        }
        else if(next != parent) {
            cycle = true;
        }
    }
    return cycle
}

bool ValidTree(unordered_map<int,vector<int>> & Graph , int n){
    if(n != graph.size()-1) return false;
    bool vis[n];
    memeset(vis, false , sizeof(vis))
    if(IsCyclic(Graph ,0 , -1 , vis)) return false;
    
    for(int i = 0 ; i < n; i++){
        if(!vis[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int nodes,edges;
    cout<<"Enter nodes and edges :";
    cin << nodes<<edges<<endl;
    
    unordered_map<int,vector<int>>edges;
    
    for(int i = 0; i < edges; i++){
        int x ,y ;
        cout<<"Enter Edge : [x,y]";
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    
    if(ValidTree(edges , n)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}
