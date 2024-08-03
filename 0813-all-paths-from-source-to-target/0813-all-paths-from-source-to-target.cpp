class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>temp;
        vector<bool>vis(graph.size(),false);
        temp.emplace_back(0);
        vis[0]  =true;
        int end = graph.size()-1;

        function<void(int)>solve = [&](int curr){
            if(curr ==  end){
                res.emplace_back(temp);
                return;
            }


            for(auto t : graph[curr]){
                if(!vis[t]){
                    vis[t] = true;
                    temp.emplace_back(t);
                    solve(t);
                    temp.pop_back();
                    vis[t] =false;
                }
            }
        }; 
        
        solve(0);
        return res;
    }
};