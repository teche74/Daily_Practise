class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int low = 0 , high = 0 , size = nums.size(), sum = 0, res = 0;
        unordered_map<int,int>map;

        while(high < size){
                
            map[nums[high]]++;
            sum+=nums[high];
            

            while(map[nums[high]] >= 2){
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