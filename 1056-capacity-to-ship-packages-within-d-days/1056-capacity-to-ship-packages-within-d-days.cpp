class Solution {
public:

    int Check(vector<int>&arr, int wt){
        int wht =  0, days = 1;

        for(int x : arr){
            if(wht + x <= wt){
                wht +=x;
            }
            else{
                days++;
                wht = x;
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& arr, int days) {
        long long low  = *max_element(arr.begin(),arr.end());

        long long high = accumulate(arr.begin(),arr.end(),0);
        int ans =-1;


        while( low <= high ){
            long long mid  = low + (high - low)/2;

            if(Check(arr, mid) <=days){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;



    }
};