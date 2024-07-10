class Solution {
public:
    bool canFinish(int size, vector<vector<int>>& arr) {
        if(!arr.size()) return true;

        unordered_map<int,vector<int>>adj;

        for(auto t : arr){
            adj[t[0]].emplace_back(t[1]);
        }

        vector<bool>vis(size, false);
        vector<bool>st(size,false);

        function<bool(int)> dfs = [&](int node){
            if (st[node]) return true;  
            if (vis[node]) return false;  

            vis[node] = true;
            st[node] = true;

            for (auto& neighbor : adj[node]) {
                if (dfs(neighbor)) return true;
            }

            st[node] = false;
            return false;
        };

        for(int i =0; i <size; i++){
            if(vis[i] == 0){
                if(dfs(i)){
                    return false;
                }
            }
        }

        return true;
    }
};