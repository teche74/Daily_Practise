class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();

        for(int i=0 ; i < size ;i++){
            while(nums[i] >= 1 && nums[i] <=size && nums[nums[i]-1] != nums[i]){
                swap(nums[nums[i]-1], nums[i]);
            }
        }

        int ind = 1;

        for(int x : nums){
            if(x == ind) ind++;
            if(x > ind) return ind; 
        }
        return ind;
    }
};