class Solution {
public:
    bool Check(vector<int> & arr, int mid, int n){
        int ind = 0 ;

        for(int i =0 ;i < arr.size() ; i++){
            int num = (arr[i] + mid -1)/mid;

            if(num <= n){
                n-=num;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quant) {
        int low = 1 , high = *max_element(quant.begin(),quant.end());

        while(low < high){
            int mid = low + (high - low)/2;

            if(Check(quant,mid,n)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        } 
        return high;
    }
};