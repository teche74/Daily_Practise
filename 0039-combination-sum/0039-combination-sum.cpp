class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>>res;
        vector<int>temp;

        function<void(int,int)> solve = [&](int index, int val){
            if(index >= cand.size()){
                if(val == 0){
                    res.emplace_back(temp);
                }
                return;
            }

            if(cand[index] <= val){
                temp.emplace_back(cand[index]);
                solve(index,val-cand[index]);
                temp.pop_back();
            }

            solve(index+1,val);
        };

        solve(0,target);

        return res;
    }
};