class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0 ;
        unordered_map<int,int>map;

        for(auto t : nums1){
            for(auto r : nums2){
                map[t+r]++;
            }
        }

        for(auto t : nums3){
            for(auto p : nums4){
                if(map.count(-t-p)) res += map[-t-p];
            }
        }

        return res;
    }
};