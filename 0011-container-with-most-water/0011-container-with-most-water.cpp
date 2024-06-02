class Solution {
public:
    int maxArea(vector<int>& arr) {
        int size = arr.size();

        int low{0} , high{size-1}, res{0};

        while(low<high){
            int ht = min(arr[low],arr[high]);
            int wt = high - low;

            res = max(res, ht * wt);

            if(arr[low] > arr[high]){
                high--;
            } 
            else{
                low++;
            }
        }
        return res;
    }
};