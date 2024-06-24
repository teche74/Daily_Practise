#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> res;

        if (arr.empty()) 
            return res;

        int top = 0, right = arr[0].size() - 1, bottom = arr.size() - 1, left = 0;

        while (top <= bottom && left <= right) {

            for (int i = left; i <= right; i++) {
                res.push_back(arr[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                res.push_back(arr[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res.push_back(arr[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(arr[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};
