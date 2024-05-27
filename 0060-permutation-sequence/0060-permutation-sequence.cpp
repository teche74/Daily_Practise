class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>temp;
        for(int i =0 ;i  <n ; i++){
            temp.emplace_back(i+1);
        }

        k--;

        while(k--){
            next_permutation(temp.begin(),temp.end());
        };

        string res=  "";

        for(int x : temp){
            res.push_back(x + '0');
        }

        return res;
    }
};