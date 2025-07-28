class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int low = 0 , high = nums.size()-1;
        long long res = 0;

        while(low < high){
            res += nums[high-1];
            low++;
            high-=2;
        }

        return res;
    }
};