class Solution {
public:
    void solve(int index, vector<int>&nums, vector<int>temp, vector<vector<int>> & store){
        store.push_back(temp);


        for(int i = index; i < nums.size(); i++){
            if( i > index && nums[i] == nums[i -1]) continue;
            temp.emplace_back(nums[i]);
            solve(i+1,nums,temp,store);
            temp.pop_back();
        }


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>store;
        vector<int>temp;
        solve(0,nums,temp,store);
        return store;
    }
};