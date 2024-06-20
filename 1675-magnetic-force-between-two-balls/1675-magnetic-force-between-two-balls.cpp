class Solution {
public:
    int Check(vector<int>&arr, int val){
        int t = arr[0];
        int count = 1;
        for(int i =1;i < arr.size() ;i++){
            if(arr[i] - t >= val){
                t = arr[i];
                count++;
            }
        }
        return count;
    }

    int maxDistance(vector<int>& position, int m) {
        int size = position.size();
        sort(position.begin(),position.end());

        int low = 0 ,  high = position[size-1] - position[0];

        while(low <= high){
            int mid = low + (high - low)/2;

            if(Check(position,mid) >= m){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};