class Solution {
public:
    int timer = 1;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];

        for(auto it :  connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>>res;
        vector<int>low(n,0), time(n,0);

        vector<int>vis(n,false);

        function<void(int,int)> solve = [&](int node, int parent){
            vis[node] = true;
            low[node] = time[node] = timer++;

            for(auto it : adj[node]){
                if(it == parent)continue;

                if(!vis[it]){
                    solve(it, node);
                    low[node] = min(low[node],low[it]);

                    if(low[it]  > time[node]){
                        res.push_back({node, it});
                    }
                }
                else{
                    low[node] = min(low[node],time[it]);
                }
            }
        };

        solve(0,-1);
        return res;
    }
};