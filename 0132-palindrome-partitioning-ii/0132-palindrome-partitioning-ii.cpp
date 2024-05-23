class Solution {
public:
    bool isPalindrome(const string &str, int low, int high) {
        while (low < high) {
            if (str[low] != str[high]) return false;
            low++;
            high--;
        }
        return true;
    }

    int solve(int low, int high, const string &s, vector<vector<int>> &map) {
        if (map[low][high] != -1) return map[low][high];

        if (isPalindrome(s, low, high)) {
            map[low][high] = 0;
            return 0;
        }

        int ans = INT_MAX;
        for (int j = low; j < high; ++j) {
            if (isPalindrome(s, low, j)) {
                ans = min(ans, 1 + solve(j + 1, high, s, map));
            }
        }

        map[low][high] = ans;
        return ans;
    }

    int minCut(string s) {
        int size = s.size();
        vector<vector<int>> map(size, vector<int>(size, -1));
        return solve(0, size - 1, s, map);
    }
};
