class Solution {
public:
    void solve(int ind, vector<vector<int>>&res, vector<int>temp, int n, int k ){
        if(temp.size() == k){
            res.emplace_back(temp);
            return;
        }

        for(int i=ind;i<=n;i++){
            temp.emplace_back(i);
            solve(i+1,res,temp,n,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>temp;

        solve(1,res,temp,n,k);
        return res;
    }
};