class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int low = 0 , high = 0, size = nums.size(),max_freq = 0 , res = 0;
        unordered_map<int,int>map;
        
        while(high < size){
            map[nums[high]]++;
            max_freq = max(max_freq, map[nums[high]]);

            while( (high - low + 1) - max_freq  > k){
                map[nums[low]]--;
                if(map[nums[low]] == 0 ) map.erase(nums[low]);
                low++;
            }
            res = max(res , map[nums[high]]);
            high++;
        }
        return res;
    }
};