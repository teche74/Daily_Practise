class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();

        for(int i =0 ;i <size; i++){
            while( nums[i] >= 1 && nums[i] <= size && nums[nums[i]-1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        int miss = 1 ;

        for(int x : nums){
            if(x == miss) miss++;
            if(x > miss) break;
        }
        return miss;
    }
};