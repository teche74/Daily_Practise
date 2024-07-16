class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int size = nums.size(),res = 0; 

        for(int i = 0 ;i  <size; i++){
            for(int j = i ; j < size; j++){
                if(abs(nums[i] - nums[j]) <= min(nums[i] ,nums[j]) )
                    res = max(res, nums[i] ^ nums[j]);
            }
        }
        return res;
    }
};