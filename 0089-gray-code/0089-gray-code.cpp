class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) {
            return {0};
        }

        vector<int> prev = grayCode(n - 1);
        vector<int> res = prev;

        int lead = 1 << (n - 1);  

        for (int i = prev.size() - 1; i >= 0; i--) {
            res.push_back(lead | prev[i]);
        }

        return res;
    }
};
