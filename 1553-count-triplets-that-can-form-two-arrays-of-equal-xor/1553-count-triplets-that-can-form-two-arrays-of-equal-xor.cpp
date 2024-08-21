class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size();

        vector<int> pre(size+1,0);

        for(int i = 0 ;i < size; i++){
            pre[i+1] = pre[i] ^ arr[i];
        }

        int count  = 0 ;

        for(int i= 0; i< size ; i++){
            for(int j = i+1; j < size ; j++){
                if(pre[i] == pre[j+1]){
                    count+=(j-i);
                }
            }
        }
        return count;
    }
};