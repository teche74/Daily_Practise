class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int low = 0 ,  high = 0 , size = arr.size() , res = 0, sum =0;

        while(high < size){
            sum += arr[high];

            if(high - low +1 >= k){
                res += (sum/k >= threshold);
                sum-=arr[low];
                low++;
            }

            high++;
        }
        return res;
    }
};