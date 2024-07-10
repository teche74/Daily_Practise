class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int low = 0 , high = nums.size()-1;

        while(low <= high){
            if(nums[low] == nums[low+1]) return nums[low];
            if(nums[high] == nums[high -1]) return nums[high];
            low++;
            high--;
        }

        return -1;
    }
};