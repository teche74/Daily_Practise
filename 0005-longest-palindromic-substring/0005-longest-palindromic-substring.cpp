class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();

        int ind = 0 , len = 0 ;

        function<int(int,int)> check = [&](int low , int high){
            while(low >= 0 && high < s.size()  && s[low] == s[high]){
                low--;
                high++;
            }
            return high - low -1;
        }  ;

        for(int i = 0 ;i  <size ; i++){
            int l1 = check(i, i);
            int l2 = check(i,i+1);

            int max_l = max(l1 , l2);

            if(max_l > len){
                len = max_l;
                ind = i - (max_l-1)/2;
            } 
        }
        return s.substr(ind, len);
    }
};