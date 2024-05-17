class Solution {
public:
    int maxArea(vector<int>& arr) {
        int low = 0 , high = arr.size()-1, res = 0;

        while(low < high){
            int ht = min(arr[low],arr[high]);
            int wt = high - low;

            res = max(ht * wt , res); 

            if(arr[low]<=arr[high]){
                low++;
            } 
            else{
                high--;
            }
        } 

        return res;
    }
};