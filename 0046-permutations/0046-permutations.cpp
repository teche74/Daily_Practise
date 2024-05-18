class Solution {
public:
    void solve(int index, vector<int>& nums, vector<vector<int>>&res){
        if(index >= nums.size()){
            res.emplace_back(nums);
            return;
        }

        for(int i = index ;i <nums.size() ;i++)
        {
            swap(nums[i],nums[index]);
            solve(index+1,nums,res);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;

        solve(0,nums,res);

        return res;
    }
};