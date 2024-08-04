class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>g;

        for(int i = 0; i < n; i++){
            if( i != n-1 ) g[i].emplace_back(i+1);
        }

        vector<int>res;

        function<int(int)> bfs = [&](int curr){
            queue<int>q;
            bool vis[n];
            memset(vis,false,sizeof(vis));


            q.push(curr);
            vis[curr] = true;
            int steps =0;

            while(!q.empty()){
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    int front = q.front();
                    q.pop();

                    if (front == n - 1) {
                        return steps;
                    }

                    for (auto t : g[front]) {
                        if (!vis[t]) {
                            q.push(t);
                            vis[t] = true;
                        }
                    }
                }
                steps++;
            }

            return steps;
        };

        for(auto t : queries){
            g[t[0]].emplace_back(t[1]);
            res.emplace_back(bfs(0));
        }

        return res;
    }
};