class Solution {
public:
    int hIndex(vector<int>& cite) {
        sort(cite.begin(),cite.end());

        int count = 0;
        int n = cite.size();

        for (int i = 0; i < n; ++i) {
            if (cite[i] >= n - i) {
                return n - i;
            }
        }

        return count; 
    }
};