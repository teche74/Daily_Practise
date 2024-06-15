class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int j = n;

        vector<int>res;

        int size= nums.size();

        for(int i =0; i< n; i++){
            res.emplace_back(nums[i]);
            if(j < size) res.emplace_back(nums[j++]);
        }

        return res;
    }
};