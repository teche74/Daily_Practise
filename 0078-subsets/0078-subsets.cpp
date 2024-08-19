class Solution {
public:
    void solve(int index, vector<int> & nums, vector<int> temp, vector<vector<int>> & res){
        if(index >= nums.size()){
            res.emplace_back(temp);
            return;
        }

        temp.emplace_back(nums[index]);
        solve(index+1,nums,temp,res);
        temp.pop_back();
        solve(index+1,nums,temp,res);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;

        solve(0 , nums , temp,res);

        return res;
    }
};