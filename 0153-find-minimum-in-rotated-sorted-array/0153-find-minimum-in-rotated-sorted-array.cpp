class Solution {
public:
    int findMin(vector<int>& nums) {
        int res  = INT_MAX , low = 0 , high = nums.size()-1;

        while(low <= high){
            int mid = low + (high - low >> 1);

            if(nums[low] <= nums[mid]){
                res = min(res , nums[low]);
                low = mid+1;
            }
            else{
                res = min(res , nums[mid]);
                high = mid-1;
            }
        }

        return res;
    }
};