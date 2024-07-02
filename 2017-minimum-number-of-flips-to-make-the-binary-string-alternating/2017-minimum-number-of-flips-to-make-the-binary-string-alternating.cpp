class Solution {
public:
    int minFlips(string s) {
        int size = s.size();

        string pattern1= "" ,  pattern2 = "";

        s+=s;

        for(int i =0 ; i < s.size() ; i++){
            pattern1 += (i & 1) ? '1' : '0';
            pattern2 += (i & 1) ? '0' : '1';  
        }

        int flip1 = 0 , flip2 = 0;

        for(int i =0 ; i <size ; i++){
            if(s[i] != pattern1[i]) flip1++;
            if(s[i] !=pattern2[i]) flip2++;
        } 

        int res = min(flip1 , flip2);


        for(int i = size ; i  < s.size() ;i++){
            if(s[i- size] != pattern1[i- size]) flip1--;
            if(s[i-size] != pattern2[i-size]) flip2--;

            if(s[i] != pattern1[i] ) flip1++;
            if(s[i] != pattern2[i] ) flip2++;


            res = min({res,flip1,flip2});
        }

        return res;

    }
};