class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size() , n = num2.size();

        int res[n+m];
        memset(res, 0, sizeof(res));

        for(int i = m-1 ; i >= 0 ;i --){
            for(int j = n-1; j >= 0 ;j--){
                int val = (num1[i] - '0') * (num2[j] - '0');

                val += res[i+j+1];
                res[i+j+1] = val%10;
                res[i+j] += val/10;
            }
        }

        string ans = "" ;

        for(int i = 0 ;i < n+m ;i++){
            if(!(ans.empty() && res[i] == 0)){
                ans.push_back(res[i] + '0');
            }
        }

        return ans == "" ? "0" : ans;
    }
};