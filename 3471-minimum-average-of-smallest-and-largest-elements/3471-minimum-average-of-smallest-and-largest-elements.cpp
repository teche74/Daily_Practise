class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        double res = INT_MAX;

        int low= 0 , high = nums.size()-1;

        while(low < high){
            res = min(res, (nums[low++] + nums[high--])/2.0);
        }

        return res;
    }
};