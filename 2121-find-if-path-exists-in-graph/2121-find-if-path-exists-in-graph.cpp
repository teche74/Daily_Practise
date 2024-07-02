class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        unordered_map<int,vector<int>>map;

        for(auto t  : edges){
            map[t[0]].push_back(t[1]);
            map[t[1]].push_back(t[0]);
        }


        bool vis[n];
        memset(vis,false,n);

        queue<int>q;

        q.push(source);
        vis[source] = true;

        while(q.size()){
            int top = q.front();
            q.pop();
            
            for(auto t : map[top]){
                if(t == destination) return true;
                if(!vis[t]){
                    q.push(t);
                    vis[t] = true;
                }
            }
        }

        return false;
    }
};