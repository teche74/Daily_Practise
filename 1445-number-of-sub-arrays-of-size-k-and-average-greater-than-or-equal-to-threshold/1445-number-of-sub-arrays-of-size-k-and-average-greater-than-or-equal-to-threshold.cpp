class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int low =0 , high = 0 , size = arr.size(), count  = 0, sum =0;

        while(high < k){
            sum+=arr[high++];
        }

        if(sum/k >= threshold) count++;

        while(high < size){
            sum+=arr[high++];
            sum-=arr[low++];

            if(sum/k  >= threshold) count++;
        }

        return count;
    }
};