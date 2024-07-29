class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        function<int(int)> solve = [&](int val){
            int low = 0 , high = nums.size()-1;

            int res = -1;
            while(low <= high){
                int mid = low + ((high - low)/2);

                if(nums[mid] == target){
                    res = mid;
                    if(val > 0){
                        low = mid+1;
                    }
                    else{
                        high = mid-1;
                    }
                }
                else if(nums[mid] >= target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            return res;
        };
        return{solve(-1),solve(1)};
    }
};