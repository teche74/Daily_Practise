class Solution {
public:

    void solve(int index, vector<int> & arr, int val, vector<int>temp, vector<vector<int>> &res){
        if(index >= arr.size()){
            if(val == 0){
                res.emplace_back(temp);
            }
            return;
        }

        if(val - arr[index] >= 0){
            temp.emplace_back(arr[index]);
            solve(index,arr,val-arr[index] , temp,res);
            temp.pop_back();
        }
        solve(index+1,arr,val,temp,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;

        vector<int>temp;

        solve(0, candidates, target,temp,res);

        return res;
    }
};