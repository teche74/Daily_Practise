class Solution {
public:
    int Check(vector<int> & arr, int weight){
        int days =1;
        int sum  =0;

        for(int i = 0 ;i  <arr.size() ; i++){
            if(sum + arr[i] > weight){
                sum = arr[i];
                days++;
            }
            else{
                sum+=arr[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& arr, int d) {
        int low =  * max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end() , 0 );

        while(low <= high){
            int mid = low + (high - low) /2;

            if(Check(arr, mid) > d){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};