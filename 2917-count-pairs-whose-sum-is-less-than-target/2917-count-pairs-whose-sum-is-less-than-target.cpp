class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int low = 0 , high = nums.size()-1, count = 0;

        while(low<high){
            int sum = nums[low] + nums[high];

            if(sum < target){
                count+=(high - low);
                low++;
            }
            else
                high--;
        }
        return count;
    }
};