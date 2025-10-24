class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int index = 0 , len = 0;

        function<int(int,int)> solve= [&](int low , int high){
            while(low >= 0 && high < size && s[low] == s[high]){
                low--;
                high++;
            }

            return high - low -1;
        };

        for(int i = 0 ; i < size; i++){
            int len1 = solve(i, i);
            int len2 = solve(i , i+1);

            int max_len  =max(len1 , len2);

            if(max_len  > len){
                len = max_len;
                index = i -(max_len -1)/2; 
            }
        }

        return s.substr(index, len);
    }
};