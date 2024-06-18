class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> res;
        int n = nums.size();
        
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                for (int i = max(0, j - k); i <= min(n - 1, j + k); ++i) {
                    res.insert(i);
                }
            }
        }
        
        return vector<int>(res.begin(), res.end());
    }
};