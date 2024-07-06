class Solution {
public:
    int check(const string  & str, int low,int high ){
        while(low >= 0 && high <str.size() && str[low] == str[high]){
            low--;
            high++;
        }
        return high - low - 1;
    }
    string longestPalindrome(string s) {
        int size = s.size() ,  ind = 0 , len = 0 ;

        for(int i =0; i <size; i ++){
            int len1 = check(s,i,i);
            int len2 = check(s,i,i+1);

            int max_len = max(len1 , len2);

            if(max_len > len){
                len = max_len;
                ind = i - (max_len-1)/2;
            }
        }

        return s.substr(ind,len);
    }
};