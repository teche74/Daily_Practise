class Solution {
public:
    int solve(vector<int>& nums, int k){
        int low =0 , high = 0 , size = nums.size() , res = 0;
        int sum =0 ;

        while(high < size){
            sum+=nums[high];

            while(sum > k){
                sum-=nums[low];
                low++;
            }

            res += (high - low+1);

            high++;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return goal > 0  ?solve(nums, goal) - solve(nums, goal-1) : solve(nums,0); 
    }
};