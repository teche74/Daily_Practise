class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int low = -1 ;
        int high = -1;

        for(int i =0; i < nums.size() ; i++){
            if(nums[i] == 1){
                low = i;
            }
            else if(nums[i] == nums.size()){
                high = i;
            }
        }
        
        if(low > high){
            return low + (nums.size()  - high - 1) - 1;
        }
        return low + (nums.size() - high - 1);
    }
};