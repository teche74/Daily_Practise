class Solution {
public:
    int trap(vector<int>& arr) {
        int size = arr.size();

        int pre[size], suff[size];

        pre[0] = arr[0], suff[size-1] =arr[size-1];

        for(int i =1; i <size; i++){
            pre[i] = max(pre[i-1] ,arr[i]);
        }

        for(int i = size-2 ; i>= 0 ; i--){
            suff[i] = max(suff[i+1],arr[i]);
        }

        int res = 0 ;

        for(int i = 0; i <size; i++){
            int val = min(pre[i] , suff[i]) - arr[i];
            if(val >= 0) res+=val;
        }
        return res;
    }
};