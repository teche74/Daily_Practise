class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1;

        while(low < high){
            int sum = nums[low] + nums[high];

            if(sum > target){
                high--;
            }
            else if(sum < target){
                low++;
            }
            else{
                return{low+1,high+1}; 
            }
        } 
        return {-1,-1};
    }
};