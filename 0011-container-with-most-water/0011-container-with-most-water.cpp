class Solution {
public:
    int maxArea(vector<int>& arr) {
        // brute 
        // int res = 0,  size = arr.size();
        // for(int i = 0; i < size ; i++ ){
        //     for(int j = i+1 ; j < size ; j++){
        //         res = max(res, (j - i) * min(arr[j],arr[i]));
        //     }
        // }

        // return res;



        // optimize

        int size = arr.size() , res = 0;

        int low = 0, high = size-1 ;

        while(low < high){
            res  = max(res, (high - low) * min(arr[low],arr[high]));

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