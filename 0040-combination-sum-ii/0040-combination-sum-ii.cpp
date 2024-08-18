class Solution {
public:
    void solve(int index, vector<int> & cand , int target , vector<int>temp , vector<vector<int>> & res){
        if(target == 0){
            res.emplace_back(temp);
            return;
        }

        for(int i = index; i < cand.size() ; i++){
            if(i > index && cand[i] == cand[i-1]) continue;
            if(cand[i]  > target) break;
            temp.emplace_back(cand[i]);
            solve(i+1,cand,target - cand[i] , temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;

        sort(candidates.begin() , candidates.end());

        solve(0 ,candidates, target , temp,res);

        return res;
    }
};