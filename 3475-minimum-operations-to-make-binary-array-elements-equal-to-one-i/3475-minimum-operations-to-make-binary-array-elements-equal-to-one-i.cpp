class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size(), count = 0 , opers = 0;

        for(int i = 0 ; i < size ; i++){
            if(nums[i] == 0 && i <= size-3){
                opers++;
                int j = i;

                while( j < size && j < i+3){
                    nums[j] = abs(nums[j] - 1);
                    j++;
                }
            }
            if(nums[i] == 0){
                count++;
            }
        }
        return count ? -1 : opers;
    }
};