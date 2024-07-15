class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minLength(n, INT_MAX);
        unordered_map<int, int> sum_map;
        sum_map[0] = -1;
        
        int curr = 0, min_len = INT_MAX, res = INT_MAX;

        for (int i = 0; i < n; ++i) {
            curr += arr[i];
            
            if (sum_map.find(curr - target) != sum_map.end()) {
                int start = sum_map[curr - target] + 1;
                int len = i - start + 1;
                if (start > 0 && minLength[start - 1] != INT_MAX) {
                    res = min(res, len + minLength[start - 1]);
                }
                min_len = min(min_len, len);
            }

            minLength[i] = min_len;
            sum_map[curr] = i;
        }

        return res == INT_MAX ? -1 : res;
    }
};