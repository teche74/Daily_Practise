class Solution {
public:
    int timer = 1;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // merko vo path dhundhne he jinke hatne se kuch nodes unvisit rh jaengi,
        // in connections ko bridge bolte.

        // Lets see How Tarjan's algo Work :
        
        vector<int>adj[n];

        for(auto t : connections){
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }


        vector<int>vis(n ,false);
        vector<int>time(n, 0);
        vector<int>low(n, 0);

        vector<vector<int>>res;

        function<void(int, int)> dfs = [&](int node, int parent) {
            vis[node] = true;
            time[node] = low[node] = timer++;

            for (int it : adj[node]) {
                if (it == parent) continue;
                if (!vis[it]) {
                    dfs(it, node);
                    low[node] = min(low[node], low[it]);

                    if (low[it] > time[node]) {
                        res.push_back({node, it});
                    }
                } else {
                    low[node] = min(low[node], time[it]);
                }
            }
        };

        dfs(0,-1);

        return res;       
    }
};