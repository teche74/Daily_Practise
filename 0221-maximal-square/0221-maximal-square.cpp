class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int max_side = 0;

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            max_side = max(max_side, maximalSquareInHistogram(heights));
        }

        return max_side * max_side;
    }

private:
    int maximalSquareInHistogram(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);  
        int max_side = 0;
        
        for(int i = 0; i < heights.size(); ++i) {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                int side = min(height, width);  
                max_side = max(max_side, side);
            }
            st.push(i);
        }

        return max_side;
    }
};
