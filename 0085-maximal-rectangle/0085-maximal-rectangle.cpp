class Solution {
public:
    void FindRight(vector<int> & arr, int temp[ ]){
        int size = arr.size();

        stack<int>st;


        for(int i =size-1; i >= 0 ; i--){
            
            while(!st.empty()  && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(st.empty()) temp[i] = arr.size();
            else temp[i] = st.top();

            st.push(i);
        }
    }


    void FindLeft(vector<int>arr, int temp[ ]){
        int size = arr.size();

        stack<int>st;


        for(int i =0; i < size ; i++){
            
            while(!st.empty()  && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(st.empty()) temp[i] = -1;
            else temp[i] = st.top();

            st.push(i);
        }
    }

    int MAH(vector<int>arr){
        int size = arr.size();

        int NGL[size] , NGR[size];


        FindRight(arr,NGR);
        FindLeft(arr,NGL);

        int res =0;

        for(int i =0; i<size; i++){
            int val = (NGR[i] - NGL[i] - 1) * arr[i];
            res = max(res,val); 
        }

        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int size = matrix[0].size();
        vector<int>arr(size,0);
        int res = 0;

        for(auto t : matrix){
            for(int i =0; i < t.size() ;i++){
                arr[i] += t[i] == '1' ? 1 : 0; 
                if(t[i] == '0'){
                    arr[i] = 0;
                }
            }
            int val = MAH(arr);
            res = max(res,val);
        }
        return res;
    }
};