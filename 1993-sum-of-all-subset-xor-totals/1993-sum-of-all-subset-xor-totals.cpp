class Solution {
public:
    int solve(int index, vector<int>&arr, int val){
        if(index == arr.size() ) return val;

        int take = solve(index+1, arr,val ^ arr[index]);
        int not_take = solve(index+1,arr,val);

        return take+not_take;
    }
    int subsetXORSum(vector<int>& arr) {
        return solve(0,arr,0);
    }
};