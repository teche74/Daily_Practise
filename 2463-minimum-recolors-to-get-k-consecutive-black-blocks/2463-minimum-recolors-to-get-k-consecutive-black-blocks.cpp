class Solution {
public:
    int minimumRecolors(string s, int k) {
        int size = s.size();
        int res = INT_MAX;
        
        for (int i = 0; i <= size - k; ++i) {
            int white = 0;

            for (int j = 0; j < k; ++j) {
                if (s[i + j] != 'B') {
                    white++;
                }
            }

            res = min(res, white);
        }

        return res;
    }
};