class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int low = 0 , high = 0 , size = s.size();
        int count = 0;
        string res = "";

        while(high < size){
            count += (s[high] == '1');

            while(count  == k){
                string ptr = s.substr(low , high - low + 1);
                if( res.empty() || ptr.size() < res.size() || ( res.size() == ptr.size() && ptr < res ) ){
                    res = s.substr(low, high - low+1);
                }

                count -= (s[low] == '1');
                low++;
                while(low < size && s[low] == '0') low++;
            }

            high++;
        }

        return res;
    }
};