class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int left = 0, size = arr.size();

        left = ::accumulate(arr.begin() ,arr.begin()+k,0);

        int right = 0;

        int i = k-1, j = size-1, sum = left ;

        while(i >=0 && size>=0){
            left-=arr[i];
            right+=arr[j];

            sum = max(sum , left + right);

            i--,j--;
        } 

        return sum;
    }
};