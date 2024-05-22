class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();

        for (int i = 0; i < size; ++i) {
            while (nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        int miss = 1;

        for(int i =0 ; i < nums.size() ;i++){
            if(miss == nums[i]) miss++;
            
            if(miss < nums[i]) break;
        }

        return miss;
    }
};