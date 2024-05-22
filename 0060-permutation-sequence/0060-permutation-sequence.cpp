class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>res;

        for(int i =1 ;i <= n; i++){
            res.emplace_back( i );
        }

        k--;
        while(k--){
            next_permutation(res.begin(),res.end());
        }

        string ans = "";

        for(int c: res){
            ans.push_back(c +'0');
        }


        return ans;
    }
};