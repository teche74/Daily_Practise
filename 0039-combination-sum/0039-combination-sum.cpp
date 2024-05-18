class Solution {
public:
    void solve(int index, vector<int>&arr, int sum , vector<int>temp , vector<vector<int>>&res){
        if(index == arr.size() ){
            if(sum == 0){
                res.emplace_back(temp);
            }
            return;
        }

        if(sum - arr[index] >= 0){
            temp.emplace_back(arr[index]);
            solve(index,arr,sum-arr[index],temp,res);
            temp.pop_back();
        }
        solve(index+1,arr,sum,temp,res);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int val) {
        vector<vector<int>>res;
        vector<int>temp;

        solve(0,arr,val,temp,res);

        return res;
    }
};