class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>map;

        int size = edges.size();

        for(auto t : edges)
        {
            map[t[0]].emplace_back(t[1]);
            map[t[1]].emplace_back(t[0]);
        }

        queue<int>q;

        bool vis[200001];
        memset(vis,false, sizeof(vis));

        q.push(source);

        while(!q.empty()){
            int front  =q.front();
            vis[front] = true;
            q.pop();

            if(front == destination) return true;

            for(int c : map[front]){
                if(!vis[c]){
                    q.push(c);
                }
            }
        }

        return false;
    }
};