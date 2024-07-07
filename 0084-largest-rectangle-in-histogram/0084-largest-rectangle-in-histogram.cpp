class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int size = arr.size();
        int smaller_left[size] , smaller_right[size];

        function<void()> calc_right= [&](){
            stack<int>st;

            for(int i = size-1 ;i>= 0; i--){
                
                while(st.size() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    smaller_right[i] = arr.size();
                }
                else{
                    smaller_right[i] = st.top();
                }
                st.push(i);
            }
        }; 

        function<void()> calc_left= [&](){
            stack<int>st;

            for(int i = 0 ;i <size ; i++){
                
                while(st.size() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    smaller_left[i] = -1;
                }
                else{
                    smaller_left[i] = st.top();
                }
                st.push(i);
            }
        }; 

        calc_right();
        calc_left();

        int res = 0;

        for(int i = 0 ; i <size; i ++){
            int val = smaller_right[i] - smaller_left[i] -1;

            res = max(res , val * arr[i]);  
        }

        return res;
    }
};