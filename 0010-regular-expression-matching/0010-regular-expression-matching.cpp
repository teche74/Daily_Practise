class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() , n = p.size();

        bool check[m+1][n+1];

        memset(check,false,sizeof(check));

        check[0][0] = true;

        for(int i = 1 ; i <= m ; i++){
            check[i][0] = false;
        }

        for(int i = 1; i <= n ; i++){
            if(p[i-1] == '*'){
                check[0][i] = check[0][i-2];
            }
        }

        for(int i =1 ;i <= m ;i++){
            for(int j =1; j <= n ;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    check[i][j] = check[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    check[i][j] = check[i][j-2] || (check[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }
                else{
                    check[i][j] =  false;
                }
            }
        }

        return check[m][n];
    }
};