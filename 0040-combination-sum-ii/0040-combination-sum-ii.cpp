class Solution {
public:
    void solve(int index, vector<int>&arr, int sum , vector<int>temp , vector<vector<int>>&res){
        
            if(sum == 0){
                res.emplace_back(temp);
                return;
            }
        

        for(int i =index ; i < arr.size() ;i++){
            if(i > index && arr[i] == arr[i-1]) continue;
            if(arr[i] > sum) break;
            temp.emplace_back(arr[i]);
            solve(i+1,arr,sum-arr[i],temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int val) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(arr.begin(),arr.end());
        solve(0,arr,val,temp,res);

        return res;
    }
};

