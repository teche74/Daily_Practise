class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() ,  n = p.size();

        int sind = 0 , pind = 0 , sstar = -1,pstar = -1;

        while(sind < m){
            if(pind < n && s[sind] == p[pind] || p[pind] == '?'){
                sind++;
                pind++;
            }
            else if(pind<n && p[pind] == '*'){
                sstar  = sind;
                pstar = pind;
                pind++;
            }
            else if(pstar != -1){
                sind = sstar+1;
                pind = pstar+1;
                sstar++;
            }
            else{
                return false;
            }
        }

        while(pind < p.size() && p[pind] == '*') pind++;

        return pind == p.size();
    }
};