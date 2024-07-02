class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // bool vis[n+1] ;
        // memset(vis, false, sizeof(vis));

        // unordered_map<int,vector<int>>adj;

        // for(auto t : trust){
        //     vis[t[0]] = true;
        //     adj[t[1]].emplace_back(t[0]);
        // }

        // for(int i = 1 ;i <= n; i++){
        //     if(!vis[i] && adj[i].size() == n-1) return i;
        // }
        // return -1;

        int in[n+1], out[n+1];

        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));

        for(auto t : trust){
            in[t[1]]++;
            out[t[0]]++;
        }

        for(int i =1; i <= n; i++){
            if(in[i] == n-1 && out[i]== 0) return i;
        }

        return -1;
        
    }
};