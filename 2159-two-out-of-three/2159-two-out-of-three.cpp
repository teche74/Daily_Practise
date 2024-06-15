class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        
        unordered_map<int,vector<int>>map;

        for(auto t : nums1){
            if(map.find(t) == map.end()){
                map[t].emplace_back(1);
            }
        }


        for(auto t : nums2){
            if(map[t].empty() || map[t].back()!=2 )
                map[t].emplace_back(2);
        }


        for(auto t : nums3){
            if(map[t].empty() || map[t].back()!=3 )
                map[t].emplace_back(3);

        }

        vector<int>res;

        for(auto t : map){
            if(t.second.size() >=2){
                res.emplace_back(t.first);
            }
        }

        return res;

    }
};