class Solution {
public:
    bool canFinish(int nodes, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>graph;

        for(auto t: edges){
            graph[t[0]].push_back(t[1]);
        }


        function<bool(void)> Cycle = [&](void){
            vector<bool>vis(nodes,false);
            vector<bool>rec(nodes,false);

            function<bool(int)> call = [&](int curr){
                vis[curr] = true;
                rec[curr] = true;

                for(int next : graph[curr]){
                    if(!vis[next] && call(next)) return true;
                    else if(rec[next]) return true;
                }

                rec[curr] = false;
                return false;
            };

            for(int i = 0 ;i < nodes; i++){
                if(!vis[i]){
                    if(call(i)) return true;
                }
            }
            return false;
        };


        return !Cycle();
    }
};