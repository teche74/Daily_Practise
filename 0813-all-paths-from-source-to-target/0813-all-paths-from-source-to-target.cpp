class Solution {
public:
    void solve(int start, int end , vector<int>temp, vector<vector<int>>&res,unordered_map<int,vector<int>>&map, vector<bool> & vis){
        if(start == end)
        {
            temp.emplace_back(end);
            res.emplace_back(temp);
            return;
        }

        // if()

        temp.emplace_back(start);
        vis[start] = true; 
        
        for(auto t : map[start]){
            if(!vis[t]){    
                solve(t,end,temp,res,map,vis);
            }
        }

        vis[start] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>map;

        for(int i = 0; i < graph.size() ; i++){
            for(auto t : graph[i]){
                map[i].emplace_back(t);
            }
        }
        int size = graph.size();

        vector<bool>vis(size,false);

        vector<vector<int>>res;
        vector<int>temp;

        solve(0, size-1 ,temp,res,map,vis);

        return res;
    }
};