class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        int size = nums.size();

        function<void(int)> solve = [&](int index){
            if(index >= size){
                res.emplace_back(nums);
                return;
            }

            set<int>used;


            for(int i = index; i < size ; i++){
                if(used.find(nums[i]) == used.end()){
                    used.insert(nums[i]);
                    swap(nums[i], nums[index]);
                    solve(index+1);
                    swap(nums[i], nums[index]);
                }
            }
        };

        solve(0);

        return res;
    }
};