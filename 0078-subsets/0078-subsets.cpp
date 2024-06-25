class Solution {
public:
    void solve(int index, vector<int>&nums, vector<int>&temp,vector<vector<int>>&res){
        res.push_back(temp);
        
        
        for(int i = index; i<nums.size() ;i++){
            temp.emplace_back(nums[i]);
            solve(i+1,nums,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;

        vector<int>temp;

        solve(0,nums,temp,res);

        return res;
    }
};