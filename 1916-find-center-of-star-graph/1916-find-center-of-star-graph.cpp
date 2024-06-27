class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>map;


        for(auto t : edges){
            map[t[0]].emplace_back(t[1]);
            map[t[1]].emplace_back(t[0]);
        }

        for(auto t : map){
            // cout<<t.first<<" : ";
            // for(auto x : t.second){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            if(t.second.size() == edges.size()) return t.first;
        }

        return -1;

    }
};