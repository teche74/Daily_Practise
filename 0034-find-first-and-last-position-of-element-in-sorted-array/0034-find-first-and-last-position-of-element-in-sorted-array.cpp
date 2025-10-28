class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();

        function<int(int,char)> getval = [&](int target , char cond){
            int low = 0 , high = size-1;
            int res = -1;

            while(low <= high){
                int mid = low + (high - low >> 1);
                if(nums[mid] == target){
                    res = mid;
                    if(cond == 'g'){
                        low = mid+1;
                    }
                    else{
                        high = mid-1;
                    }
                }
                else if(nums[mid] > target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }

            }
            return res;
        };

        return {getval(target , 's') , getval(target , 'g')};
    }
};