class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0 , size  = nums.size();
        if(nums[0] >= target) return  0;
        if(nums[size-1] < target) return size;

        for(int i = size ; i >= 1 ;i/=2){
            while(index + i < size && nums[index+i] < target){
                index+=i;
            }
        }
        return index+1;
    }
};