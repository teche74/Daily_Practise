class Solution {
public:
    vector<int> shuffle(vector<int>& arr, int mid) {
        int size = arr.size();
        vector<int> res(size,0);

        for (int i = 0; i < mid; ++i) {
            res[2 * i] = arr[i];
            res[2 * i + 1] = arr[mid + i];
        }

        return res;
    }
};