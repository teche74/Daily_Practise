class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;

        int low = 0 , high = nums.size()-1;

        while(low < high){
            int val = nums[low] +  nums[high];
            if(val == target){
                return vector<int>{low+1, high+1};
            }
            else if(val > target){
                high--;
            }
            else{
                low++;
            }
        } 

        return vector<int>{-1,-1};
    }
};