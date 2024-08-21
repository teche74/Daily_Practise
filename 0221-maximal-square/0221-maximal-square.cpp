class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        vector<int>heights(matrix[0].size() , 0);

        function<int(void)> solve = [&](){
            stack<int>st;
            heights.push_back(0);
            int max_side = 0;

            for(int i = 0 ; i < heights.size() ; i++){
                while(!st.empty() && heights[i] < heights[st.top()]){
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? i : (i - st.top() - 1);
                    int side =  min(height, width);
                    max_side = max(max_side , side);
                }
                st.push(i);
            }
            return max_side;
        };

        int res = 0 ;
        
        for(auto t : matrix){
            int index = 0;
            for(int val :  t){
                if(val == '0'){
                    heights[index] = 0;
                }
                else{
                    heights[index]+=(val - '0');
                }
                index++;
            }

            res = max(res, solve());
        }
        return res*res;
    }
};