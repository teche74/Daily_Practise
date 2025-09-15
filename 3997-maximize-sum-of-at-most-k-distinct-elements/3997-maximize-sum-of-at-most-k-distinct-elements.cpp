class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int size = nums.size();

        sort(nums.begin() , nums.end());
        vector<int>res;

        for(int i = size-1 ; i >= 0; i--){
            if(i < size-1 && nums[i] == nums[i+1]) continue;
            res.push_back(nums[i]);
            if(res.size() == k) break;
        }

        return res;
    }
};