class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int first = -1 , last = -1 , size = nums.size();

        for(int i  = size ; i>=1 ;i/=2){
            while(first + i < size && nums[first + i] < target) first+=i;
            while(last + i < size && nums[last+ i] <= target) last+=i;
        }

        vector<int>res;

        for(int i = first+1 ; i<= last ; i++){
            res.emplace_back(i);
        }

        return res;

    }
};