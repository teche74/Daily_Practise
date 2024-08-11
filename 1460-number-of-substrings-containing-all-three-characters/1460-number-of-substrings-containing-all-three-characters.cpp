class Solution {
public:
    int numberOfSubstrings(string s) {
        int ca = 0 , cb = 0 , cc = 0 ;
        int low = 0 , high = 0 , size = s.size() , res = 0;
        bool all = false;

        while(high  < size){
            ca += (s[high] == 'a');
            cb += (s[high] == 'b');
            cc += (s[high] == 'c');

            all = (ca > 0) & (cb > 0) & (cc > 0);


            while(all){
                res += size - high;
                ca -= (s[low] == 'a');
                cb -= (s[low] == 'b');
                cc -= (s[low] == 'c');

                all = (ca > 0) & (cb > 0) & (cc > 0);
                low++;
            } 

            high++;
        }

        return res;
    }
};