class Solution {
public:
    void solve(int ele , vector<vector<int>>&res, vector<int>temp, vector<bool> & vis , vector<vector<int>>&graph ){
        if(ele == graph.size()-1){
            temp.push_back(ele);
            res.emplace_back(temp);
            return ;
        }
        temp.emplace_back(ele);
        vis[ele] = true;

        for(auto t : graph[ele]){
            if(!vis[t]){
                solve(t,res,temp,vis,graph);
            }
        }
        temp.pop_back();
        vis[ele] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int size  = graph.size();

        vector<bool>vis(size,false);

        vector<vector<int>>res;
        vector<int>temp;

        solve(0 , res,temp,vis,graph);

        return res;
    }
};