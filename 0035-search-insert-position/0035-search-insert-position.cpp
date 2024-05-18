class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size(),index =-1;

        for(int i = size ;i >=1 ;i/=2){
            while(index + i < size && nums[index+i] < target) index +=i;
        }

        return index+1;
    }
};