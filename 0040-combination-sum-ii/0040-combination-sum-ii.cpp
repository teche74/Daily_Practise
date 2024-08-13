class Solution {
public:
    void solve(int index , vector<int> & cand , int val , vector<vector<int>> &res , vector<int>temp){
        if(val ==  0){
            res.emplace_back(temp);
            return;
        }

        for(int i = index ; i < cand.size(); i++){
            if( i> index && cand[i] == cand[i-1]) continue;
            if(cand[i] > val)break;
            temp.emplace_back(cand[i]);
            solve(i+1,cand,val - cand[i] , res, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;

        sort(candidates.begin() , candidates.end());

        solve( 0 , candidates , target , res, temp);

        return res;
    }
};