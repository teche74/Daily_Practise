class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = 0, size = nums.size();

        for(int i = size  ;i >=1 ;i/=2){
            while(index + i <  size && nums[index + i] <= target) index+=i;
        }

        if(nums[index] == target){
            return index;
        }
        return -1;
    }
};