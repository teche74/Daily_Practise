class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;

        int size = nums.size();

        function<void(int)> solve = [&](int index){
            if(index >= size){
                res.emplace_back(nums);
                return ;
            }

            for(int i = index; i < size ; i++){
                swap(nums[i] , nums[index]);
                solve(index+1);
                swap(nums[i], nums[index]);
            }
        };

        solve(0);

        return res;
    }
};