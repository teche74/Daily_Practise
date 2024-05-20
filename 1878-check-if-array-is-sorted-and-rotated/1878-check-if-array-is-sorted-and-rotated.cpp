class Solution {
public:
    bool check(vector<int>& arr) {
        int size = arr.size();

        int count  = 0 ;

        for(int i =1 ;i  <size; i++){
            if(arr[i-1] > arr[i]){
                count++;
            }
        } 

        if(arr[size-1] > arr[0]) count++;

        return count<=1;       
    }
};