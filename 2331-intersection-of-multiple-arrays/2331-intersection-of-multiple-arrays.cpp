class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int>map;

        for(auto t : nums){
            for(auto x : t){
                map[x]++;
            }
        }

        vector<int>res;

        for(auto it : map){
            if(it.second == nums.size()){
                res.emplace_back(it.first);
            }
        }

        sort(res.begin(),res.end());
        return res;
    }
};