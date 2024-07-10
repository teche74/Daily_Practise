class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>map;
        for(auto t : nums){
            map[t]++;
            if(map[t] > 1) return t;
        }
        return -1;
    }
};