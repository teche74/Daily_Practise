class Solution {
public:
    int minFlips(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
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
            if(s[i- size] != pattern1[i- size]) flip1--; // agr last or first element different he to simple shift krna he operation perform ki jrurt nhi isliye flip minus kiya .
            if(s[i-size] != pattern2[i-size]) flip2--; // same upar vala logic for pattern2.

            if(s[i] != pattern1[i] ) flip1++; // ab jab window ki batt hori he to dhyan rkhna he ki jo operation perform hua vo window ke andr vale elements ke liye hi ho jesi hi bhar jata to flips increase kr do . 
            if(s[i] != pattern2[i] ) flip2++;


            res = min({res,flip1,flip2});
        }

        return res;

    }
};