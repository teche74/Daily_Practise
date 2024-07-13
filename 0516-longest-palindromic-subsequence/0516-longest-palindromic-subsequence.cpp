class Solution {
public:
    bool ispalli(string s) {
        int low = 0, high = s.size() - 1;
        
        while (low <= high) {
            if (s[low] != s[high]) return false;
            low++;
            high--;
        }
        
        return true;
    }
    
    vector<vector<int>> memo;
    
    int solve(int left, int right, string& s) {
        if (left > right) return 0;
        
        if (left == right) return 1; 
        
        if (memo[left][right] != -1) return memo[left][right];
        
        if (s[left] == s[right]) {
            return memo[left][right] = 2 + solve(left + 1, right - 1, s);
        } else {
            return memo[left][right] = max(solve(left + 1, right, s), solve(left, right - 1, s));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 0) return 0;
        memo.assign(n, vector<int>(n, -1));
        
        return solve(0, n - 1, s);
    }
};
