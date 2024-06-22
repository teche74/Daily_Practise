class Solution {
public:
    int check(const string & s, int low, int high){
        while(low >= 0 && high  < s.size() && s[low] == s[high]){
            low--;
            high++;
        }
        return high - low - 1;
    }
    string partition(const string & s){
        int size = s.size();

        int ind = 0 , len =  0; 

        for(int i =0; i < size ; i++){
            int len1 = check(s, i,i);
            int len2 = check(s, i, i+1);

            int maxi = max(len1 , len2);

            if(maxi > len){
                ind = i - (maxi -1)/2;
                len = maxi;
            }
        }

        return s.substr(ind, len);
    }

    string manchars(const string & s){
        string temp = "$";

        for(char ch : s){
            temp.push_back('|');
            temp.push_back(ch);
        }

        temp.push_back('|');
        temp.push_back('#');
        

        int lps[temp.size()];

        memset(lps, 0, sizeof(lps));

        int right = 0 , centre = 0;

        for(int i =1; i < temp.size()-1 ; i++){
            int mirror = 2 * centre  - i;

            if (i < right) {
                lps[i] = min(right - i, lps[mirror]);
            }


            while( temp[i + lps[i] + 1] == temp[i - lps[i] - 1]){
                lps[i]++;
            }

            if( i + lps[i] > right ){
                right = i+ lps[i];
                centre = i;
            }
        }

        int max_len = 0 , max_centre = 0;

        for(int i =1; i < temp.size()-1 ; i++){
            if(lps[i] > max_len){
                max_len = lps[i];
                max_centre = i;
            }
        }

        int ind = (max_centre - max_len)/2;

        return s.substr(ind,max_len);

    }
    string longestPalindrome(string s) {
        // return partition(s);
        return manchars(s);
    }
};