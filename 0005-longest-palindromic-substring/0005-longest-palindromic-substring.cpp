class Solution {
public:
    string longestPalindrome(string s) {
        string temp = "$";

        for(char ch : s){
            temp.push_back('|');
            temp.push_back(ch);
        }
        temp.push_back('|');
        temp.push_back('@');

        int size= temp.size();

        int lps[size];
        memset(lps, 0 ,sizeof(lps));
        int right = 0 , centre = 0 ; 

        for(int i = 1; i < size-1 ; i++){
            int mirror = 2 * centre - i;

            if(i < right){
                lps[i] = min(right - i , lps[mirror]);
            }

            while( temp[ i + lps[i] +1]  == temp[i - lps[i] -1] ){
                lps[i]++;
            }

            if( i + lps[i] > right){
                centre = i;
                right = i + lps[i];
            }
        }

        int max_centre = 0 , max_len = 0;

        for(int i = 1 ;i < size-1 ; i++){
            if(max_len < lps[i]){
                max_len = lps[i];
                max_centre = i;
            }
        }

        return s.substr((max_centre-max_len)/2, max_len);
    }
};