// class Solution {
// public:
//     int solve(int index, const string & s){
//         if(index >= s.size()){
//             return 1;
//         }

//         if(s[index] == '0') return 0;


//         int single_digit = solve(index+1,s);
//         int double_digit = 0;

//         if(index+1 < s.size() && stoi(s.substr(index,2)) <= 26){
//             double_digit = solve(index+2 ,s);
//         }

//         return single_digit + double_digit;
//     }
//     int numDecodings(string s) {
//         return solve(0,s);
//     }
// };




// class Solution {
// public:
//     int solve(int index, const string & s, vector<int> &dp){
//         if(index >= s.size()){
//             return 1;
//         }

//         if(s[index] == '0') return 0;
//         if(dp[index] != -1) return dp[index];


//         int single_digit = solve(index+1,s,dp);
//         int double_digit = 0;

//         if(index+1 < s.size() && stoi(s.substr(index,2)) <= 26){
//             double_digit = solve(index+2 ,s,dp);
//         }

//         return dp[index] = single_digit + double_digit;
//     }
//     int numDecodings(string s) {
//         int size = s.size();
//         vector<int>dp(size,-1);
//         return solve(0,s,dp);
//     }
// };


class Solution {
public:
    int numDecodings(string s) {
        int  n = s.size();
        if(n == 0 ) return 0;

        vector<int> dp(n+1,0);

        // puri string ko decode krne ka sirf 1 tareka he  ... 
        dp[n] =1;

        for(int i= n-1; i>= 0 ; i--){
            if(s[i] == '0'){
                dp[i] = 0;
            }
            else{
                dp[i] = dp[i+1]; // single digit ke liye;

                if(i+1 <n && (s[i] == '1' || (s[i]== '2' && s[i+1] >= '0' && s[i+1] <='6'))) {
                    dp[i] += dp[i+2];
                }
            }
        }

        return dp[0];
    }
};