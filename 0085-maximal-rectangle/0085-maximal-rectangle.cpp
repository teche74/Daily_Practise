#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
void FindGreaterRight(vector<int> & arr, int aux[ ] ){
        stack<int>st;

        for(int i = arr.size()-1 ; i >= 0 ; i--){

            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(st.empty()) aux[i] = arr.size();
            else aux[i] = st.top();


            st.push(i);
        }
    }

    void FindGraterLeft(vector<int> & arr, int aux[ ] ){
        stack<int>st;

        for(int i = 0 ; i < arr.size() ; i++){

            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(st.empty()) aux[i] = -1;

            else aux[i] = st.top();

            st.push(i);
        }
    }

    int CalcMAH(vector<int>&arr){
        int size = arr.size();

        int greater_right[size], greater_left[size];

        FindGreaterRight(arr,greater_right);

        FindGraterLeft(arr,greater_left);

        int res = 0;

        for(int i =0; i < size ; i++){
            int val = (greater_right[i] - greater_left[i] -1) * arr[i];
            res = max(res,val);
        }

        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>arr(matrix[0].size(),0);

        int res = 0;

        for(auto t : matrix){
            int i = 0;
            while( i < t.size()){
                if(t[i] == '0') arr[i] = 0;
                else arr[i]+=1;
                i++;
            }
            res = max(res, CalcMAH(arr));
        }   

        return res;
    }
};
auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return '$';
}();