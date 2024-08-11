class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size(), count = 0 , opers = 0;

        for(int i = 0 ; i <= size-3 ; i++){
            if(nums[i] == 0){
                opers++;
                int j = i;

                while( j < size && j < i+3){
                    nums[j] = abs(nums[j] - 1);
                    j++;
                }
            }
        }

        for(int  x : nums){
            // cout<<x<<" ";
            if(x == 0) return -1;
        }
        return opers;
    }
};