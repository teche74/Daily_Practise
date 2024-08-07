class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();

        int low = 0 , high  =size-1, res = INT_MAX;

        while(low <= high){
            int mid =  low + (high - low)/2;
            if(nums[mid] >= nums[low]){
                res = min(res,nums[low]);
                low = mid+1;
            }
            else{
                res = min(res,nums[mid]);
                high = mid-1;
            }
        }
        return res;
    }
};