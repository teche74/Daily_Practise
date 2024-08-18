class Solution {
public:
    string centreexpand(const string   &str){
        int size = str.size();
        int ind = 0 , len = 0 ;


        function<int(int,int)> check = [&](int low, int high){
            while(low >= 0 && high  < size && str[low] == str[high]){
                low--;
                high++;
            }
            return high - low - 1;
        }; 


        for(int i = 0 ;i  <size; i++){
            int len1 = check(i ,i);
            int len2 = check(i , i+1);

            int max_len = max(len1 , len2);

            if(len < max_len){
                len = max_len;
                ind = i - (len-1)/2;
            }
        }

        return str.substr(ind,len);
    }
    string longestPalindrome(string s) {
        // centre Expand apporach.
        return centreexpand(s);
    }
};