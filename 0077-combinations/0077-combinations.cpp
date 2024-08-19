class Solution {
public:
    void solve(int start, int end ,int size , vector<int> temp , vector<vector<int>> & res){
        if(temp.size() == size){
            res.emplace_back(temp);
            return;
        }

        for(int i = start; i <= end ; i++){
            temp.emplace_back(i);
            solve(i+1,end,size,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>temp;

        for(int i = 1 ; i <= n ; i++){
            temp.emplace_back(i);
            solve(i+1,n,k,temp,res);
            temp.pop_back();
        }

        return res;
    }
};