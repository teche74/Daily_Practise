class Solution {
public:
    int check(const string  & s, int low,  int high){
        while(low>= 0 && high < s.size() && s[low] == s[high] ){
            low--;
            high++;
        }
        return high - low-1;
    } 
    string longestPalindrome(string s) {
        int size = s.size();

        int ind = 0, len =0 ;

        for(int i =0 ; i <size; i++){

            int len1 = check(s,i,i);
            int len2 = check(s,i,i+1);

            int maxi = max(len1 , len2);

            if(maxi > len){
                len = maxi ;
                ind  = i - (maxi  -1)/2;
            }
        }

        return s.substr(ind, len);
    }
};