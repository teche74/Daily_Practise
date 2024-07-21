class Solution {
public:
    int findMinMoves(vector<int>& arr) {
        int size = arr.size();

        int total = ::accumulate(arr.begin(),arr.end(),0);

        if(total % size != 0) return -1;

        int each  = total/size;

        int res = 0, curr = 0;

        for(int i =0 ; i < size ; i++){
            curr += arr[i] - each;
            res = max(res , max(abs(curr) , arr[i] - each ));
        } 

        return res;
    }
};