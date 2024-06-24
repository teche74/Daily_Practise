class Solution {
public:
    void solve(int index, vector<int> & arr, int val , vector<int>temp, vector<vector<int>>&res){
        if(val == 0){
            res.emplace_back(temp);
            return;
        }

        for(int i =index; i<arr.size() ;i++){
            if(i > index && arr[i] == arr[i-1]) continue;
            if(arr[i] > val) break;
            temp.emplace_back(arr[i]);
            solve(i+1,arr,val-arr[i],temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;

        sort(candidates.begin(),candidates.end());

        solve(0, candidates,target,temp,res);

        return res;
    }
};