class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // # no of components 

        // unordered_map<int,vector<int>>map;

        // for (const auto& edge : edges) {
        //     map[edge[0]].emplace_back(edge[1]);
        // }

        // set<int>vals;
        // vector<bool>vis(n,false);

        // function<void(int)> bfs = [&](int curr){
        //     queue<int>q;

        //     q.push(curr);

        //     while(!q.empty()){
        //         int front = q.front();
        //         q.pop();

        //         for(auto t : map[front]){
        //             if(!vis[t]){
        //                 if(vals.find(t) != vals.end()){
        //                     vals.erase(t);
        //                 }
        //                 vis[t] = true;
        //                 q.push(t);
        //             }
        //         }
        //     }
        // };

        // for(int i = 0; i < n ; i++){
        //     if(!vis[i]){
        //         vals.insert(i);
        //         bfs(i);
        //     }
        // }

        // return {vals.begin(),vals.end()};





        // # get node with indegree zeroes;

        vector<int>indegree(n+1,0);


        for(auto t : edges){
            indegree[t[1]]++;
        }

        vector<int>res;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                res.emplace_back(i);
            }
        }

        return res;
    }
};