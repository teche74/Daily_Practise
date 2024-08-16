class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double res = INT_MAX , size = nums.size();

        int low = 0 , high = size-1;

        sort(nums.begin(), nums.end());

        while(low < high){
            res = min(res, (double)(nums[low] + nums[high])/2);
            low++;
            high--;
        }
        return res;
    }
};