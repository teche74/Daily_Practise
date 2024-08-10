class Solution {
public:
    int findLHS(vector<int>& nums) {
        int low = 0 , high = 0 ,  size = nums.size(), res = 0;

        sort(nums.begin(), nums.end());

        while(high < size){
            while(nums[high] - nums[low] > 1){
                low++;
            } 

            if(nums[high] - nums[low] == 1)
                res = max(res, high - low+1);
            
            high++;
        }

        return res;
    }
};