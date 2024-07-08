class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ind  = 0 ,size = arr.size();

        for(int i = size; i >= 1 ; i/=2 ){
            while(ind + i + 1 < size && arr[ind + i] >= arr[ind+i-1]) ind+=i;
        }

        return ind;
    }
};