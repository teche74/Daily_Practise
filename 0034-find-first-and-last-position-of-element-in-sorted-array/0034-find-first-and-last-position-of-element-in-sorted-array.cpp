class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int tar) {
        auto get = [&arr, &tar](bool val){
            int low =0 , high = arr.size()-1;
            int ans= -1;

            while(low <= high){
                int mid = low + ( high - low)/2;

                if(arr[mid] == tar){
                    ans = mid;

                    if(val){
                        low = mid+1;
                    }
                    else{
                        high = mid-1;
                    }
                }
                else if(arr[mid] > tar){
                    high  = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            return ans;
        };


        return {get(false),get(true)};
    }
};