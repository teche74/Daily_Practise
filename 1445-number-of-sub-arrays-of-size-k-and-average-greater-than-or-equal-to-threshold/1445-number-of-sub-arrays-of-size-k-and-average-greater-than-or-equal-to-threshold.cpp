class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count  = 0 ;

        int low = 0 , high = 0 ,size = arr.size(), sum = 0;

        while(high < size){
            sum += arr[high];

            if(high >= k-1){
                count+=( (sum/k) >=threshold);
                sum-=arr[low];
                low++;
            }
            high++;
        }

        return count;
    }
};