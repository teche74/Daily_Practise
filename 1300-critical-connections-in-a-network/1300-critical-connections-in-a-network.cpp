class Solution {
public:
    int timer = 1;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>adj[n];

        for(auto t : connections){
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }

        vector<bool>vis(n,false);
        vector<int>low(n,0);
        vector<int>time(n,0);
        vector<vector<int>>res;

        function<void(int,int)> dfs = [&](int node, int parent){
            vis[node] = true;
            low[node]= time[node] = timer++;

            for(auto t : adj[node]){
                if(t == parent) continue;
                if(!vis[t]){
                    dfs(t,node);

                    low[node] = min(low[node], low[t]);

                    if (low[t] > time[node]) {
                        res.push_back({node, t});
                    }
                }
                else{
                    low[node] = min(time[t], low[node]);
                }
            }
        };

        dfs(0,-1);

        return res;
    }
};