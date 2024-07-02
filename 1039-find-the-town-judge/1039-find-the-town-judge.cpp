class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        bool vis[n+1] ;
        memset(vis, false, sizeof(vis));

        unordered_map<int,vector<int>>adj;

        for(auto t : trust){
            vis[t[0]] = true;
            adj[t[1]].emplace_back(t[0]);
        }

        for(int i = 1 ;i <= n; i++){
            if(!vis[i] && adj[i].size() == n-1) return i;
        }
        return -1;

        
    }
};