// centre Expansion .

// class Solution {
// public:
//     int check(const string  & str, int low,int high ){
//         while(low >= 0 && high <str.size() && str[low] == str[high]){
//             low--;
//             high++;
//         }
//         return high - low - 1;
//     }
//     string longestPalindrome(string s) {
//         int size = s.size() ,  ind = 0 , len = 0 ;

//         for(int i =0; i <size; i ++){
//             int len1 = check(s,i,i);
//             int len2 = check(s,i,i+1);

//             int max_len = max(len1 , len2);

//             if(max_len > len){
//                 len = max_len;
//                 ind = i - (max_len-1)/2;
//             }
//         }

//         return s.substr(ind,len);
//     }
// };

// manchars algo

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         auto manchars  =[&]()->string{
//             int size = s.size();
//             if (size == 0) return "";
//             string temp = "@";

//             for(char ch : s){
//                 temp.push_back('|');
//                 temp.push_back(ch);
//             }
//             temp.push_back('|');
//             temp.push_back('#');


//             vector<int>lps(temp.size(),0);

//             int right = 0 , centre = 0;

//             for(int i=1;i <temp.size()-1;i++){
//                 int mirror = 2 * centre - i;

//                 if(i <right){
//                     lps[i] = min(right - i, lps[mirror]);
//                 }

//                 while(temp[i+lps[i]+1] == temp[i-lps[i]-1]){
//                     lps[i]++;
//                 }

//                 if(i+lps[i] > right){
//                     right = i+lps[i];
//                     centre = i;
//                 }
//             }

//             int centre_index = 0 ;
//             int max_len = 0;

//             for(int i=1;i <lps.size()-1;i++){
//                 if(lps[i] > max_len){
//                     max_len = lps[i];
//                     centre_index = i;
//                 }
//             }

//             return s.substr((centre_index - max_len) / 2, max_len);
//         }  ;

//         return manchars();
//     }
// };

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        vector<vector<int>>dp(size ,vector<int>(size,0));


        for(int i=0;i<size;i++){
            dp[i][i] = 1; // all single characters are pallindome;
        }

        int start = 0 , max_len = 1;

        for(int i = 0; i <size-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1]++;
                start = i ;
                max_len = 2;
            }
        }

        for(int len =3 ; len <=size ; len++){ // all length from 2 to n
            for(int i =0; i <= size - len ; i++){
                int j = i + len - 1;
                if(s[i] == s[j] && dp[i+1][j-1] >0 ){
                    dp[i][j]++;
                    start = i;
                    max_len = len;
                }
            }
        }

        return s.substr(start,max_len);
    }
};