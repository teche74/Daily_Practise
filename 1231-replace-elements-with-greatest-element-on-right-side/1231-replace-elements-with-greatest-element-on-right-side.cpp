class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();
        vector<int> res(size);
        int maxi = -1;

        for (int i = size - 1; i >= 0; i--) {
            res[i] = maxi;
            maxi = max(maxi, arr[i]);
        }

        return res;
    }
};