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

    string manchers(const string  & str ){
        string s = "$";

        for(char ch : str){
            s.push_back('|');
            s.push_back(ch);
        }

        s.push_back('|');
        s.push_back('@');

        int size = s.size();
        int lps[size];
        memset(lps, 0 ,sizeof(lps));

        int centre = 0 , right =  0;

        for(int i = 1; i  < size -1 ; i++){
            int mirror  = 2 * centre - i;

            if(i < right){
                lps[i] = min( right - i, lps[mirror]);
            }

            while(s[i + lps[i] + 1] == s[i - lps[i] - 1]){
                lps[i]++;
            }

            if(i + lps[i]  > right){
                centre =  i;
                right = i + lps[i];
            }
        }

        int max_len = 0 , max_centre = 0;

        for(int i  =1; i  < size ; i++){
            if(lps[i] >  max_len){
                max_len = lps[i];
                max_centre = i;
            }
        } 


        return str.substr((max_centre - max_len)/2 , max_len); 
    }

    string longestPalindrome(string s) {
        // centre Expand apporach.
        // return centreexpand(s);


        // manchers algorith
        return manchers(s);
    }
};