class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0 , high = arr.size()-1, size = arr.size();

        while(low <= high){
            int mid = low +  (high - low)/2;

            if(mid + 1 < size && arr[mid] < arr[mid+1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};