class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size() , n = num2.size();

        vector<int>res(m+n, 0);

        for(int i = m-1 ; i >=0 ;i--){
            for(int j = n-1; j >= 0 ; j--){
                int val = (num1[i] - '0') * (num2[j] - '0') + res[i+j+1];
                res[i+j]  += (val/10);  
                res[i+j+1] = (val%10);
            }
        }

        string ans = "";

        for(int x : res){
            if( !(x == 0 && ans.empty()) ){
                ans.push_back(x + '0');
            }
        }
        return ans.empty() ? "0" : ans;
    }
};