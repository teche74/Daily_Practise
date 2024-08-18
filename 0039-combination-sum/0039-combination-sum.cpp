class Solution {
public:
    void solve(int index, vector<int> & cand , int target , vector<int> temp ,  vector<vector<int>> & res){
        if(index >= cand.size()){
            if(target == 0)
                res.emplace_back(temp);
            return;
        }

        if(cand[index] <= target){
            temp.emplace_back(cand[index]);
            solve(index,cand, target  - cand[index], temp,res);
            temp.pop_back();
        }
        solve(index+1,cand,target,temp,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;

        solve( 0, candidates, target , temp, res);

        return res;
    }
};