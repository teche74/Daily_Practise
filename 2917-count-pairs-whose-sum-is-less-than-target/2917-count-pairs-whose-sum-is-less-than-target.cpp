class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int size = nums.size();

        sort(nums.begin(), nums.end());

        int low =0 , high = nums.size()-1, count = 0;

        while(low < high){

            if(nums[low] + nums[high] < target){
                count+=high -low;
                low++;
            }
            else
                high--;
        }

        return count;
    }
};