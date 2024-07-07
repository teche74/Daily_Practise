class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        vector<int> arr(matrix[0].size(), 0);
        int res = 0;

        auto calculate = [&](vector<int>& arr) {
            int size = arr.size();
            vector<int> smaller_left(size), smaller_right(size);

            auto calc_right = [&]() {
                stack<int> st;
                for (int i = size - 1; i >= 0; i--) {
                    while (!st.empty() && arr[st.top()] >= arr[i]) {
                        st.pop();
                    }
                    if (st.empty()) {
                        smaller_right[i] = arr.size();
                    } else {
                        smaller_right[i] = st.top();
                    }
                    st.push(i);
                }
            };

            auto calc_left = [&]() {
                stack<int> st;
                for (int i = 0; i < size; i++) {
                    while (!st.empty() && arr[st.top()] >= arr[i]) {
                        st.pop();
                    }
                    if (st.empty()) {
                        smaller_left[i] = -1;
                    } else {
                        smaller_left[i] = st.top();
                    }
                    st.push(i);
                }
            };

            calc_right();
            calc_left();

            int res = 0;
            for (int i = 0; i < size; i++) {
                int val = smaller_right[i] - smaller_left[i] - 1;
                res = max(res, val * arr[i]);
            }
            return res;
        };

        for (auto& t : matrix) {
            for (int i = 0; i < t.size(); i++) {
                if (t[i] == '0') {
                    arr[i] = 0;
                } else {
                    arr[i] += (t[i] - '0');
                }
            }
            res = max(res, calculate(arr));
        }

        return res;
    }
};
