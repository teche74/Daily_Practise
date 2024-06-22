class Solution {
public:
    int maxArea(vector<int>& arr) {
        int size = arr.size();

        int low= 0 , high = size-1, res = 0;

        while(low < high){
            res = max(res , (int)(high - low) * min(arr[low],arr[high]));

            if(arr[low] < arr[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return res;
    }
};