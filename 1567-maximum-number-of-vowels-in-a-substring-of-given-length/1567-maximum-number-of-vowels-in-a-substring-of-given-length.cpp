class Solution {
public:
    bool isvowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch== 'u';
    }

    int maxVowels(string s, int k) {
        int low = 0 , high = 0 , size = s.size() , res = 0 , count  = 0;

        while(high < size){
            count+=(isvowel(s[high]));

            while(high - low  + 1 > k){
                count -= (isvowel(s[low]));
                low++;
            }

            res = max(res, count);
            high++;
        } 

        return res;
    }
};