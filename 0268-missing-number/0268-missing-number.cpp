class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort and find
        sort(nums.begin() , nums.end());
        int size=  nums.size();

        for(int i = 0; i < size ; i ++){
            if(nums[i] != i) return i;
        }

        return nums.size();
    }
};