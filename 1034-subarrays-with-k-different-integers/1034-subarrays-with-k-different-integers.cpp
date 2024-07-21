class Solution {
public:
    int helper(vector<int> & nums , int dist){
        int low = 0 , high = 0 , size = nums.size(), res = 0;
        unordered_map<int,int>map;

        while(high < size){
            map[nums[high]]++;

            while(map.size() > dist){
                map[nums[low]]--;
                if(map[nums[low]] == 0){
                    map.erase(nums[low]);
                }
                low++;
            }
            res+= (high - low+1);
            high++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums , k) - helper(nums, k-1);
    }
};