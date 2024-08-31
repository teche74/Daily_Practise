class Solution {
public:
    int solve(string  & s , int low , int  high){
        while(low >= 0  && high  < s.size() && s[low] == s[high]){
            low--;
            high++;
        }

        return high - low - 1;
    }

    string manchers(const string & str){
        string ptr = "$";

        for(char ch : str){
            ptr.push_back('|');
            ptr.push_back(ch);
        }
        ptr.push_back('|');
        ptr.push_back('@');

        int size = ptr.size();

        vector<int>lps(size,0);

        int right = 0 , centre = 0;

        for(int i = 1 ; i < size-1; i++){
            int mirror = 2 * centre - i;

            if(right > i){
                lps[i] = max(right - i,lps[mirror]);
            }

            while(ptr[i + lps[i] + 1] == ptr[i - lps[i] - 1]){
                lps[i]++;
            }

            if(i + lps[i] > right){
                centre = i;
                right = i + lps[i];
            }
        }

        int max_centre = 0 , max_len = 0;

        for(int i =1; i < lps.size()-1 ; i++){
            if(lps[i] > max_len){
                max_len = lps[i];
                max_centre = i;
            }
        }

        return str.substr((max_centre  - max_len)/2  , max_len);
    }

    string longestPalindrome(string s) {
        // int size = s.size();
        // int ind = 0 , len = 0 ;

        // for(int i = 0 ; i < size; i++){
            
        //     int len1 = solve(s,i,i);
        //     int len2 = solve(s,i,i+1);

        //     int max_len = max(len1,len2);

        //     if(max_len > len){
        //         len = max_len;
        //         ind = i - (max_len -1)/2;
        //     }
        // }

        // return s.substr(ind,len);

        return manchers(s); 
    }
};