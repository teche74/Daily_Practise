class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>map;

        int low = 0, high = 0 , size = nums.size() , res = 0, sum = 0;

        while(high < size){
            sum+=nums[high];
            map[nums[high]]++;

            while(map[nums[high]] > 1){
                sum-=nums[low];
                map[nums[low]]--;
                low++;
            }

            res = max(res, sum);
            high++;
        }
        return res;
    }
};