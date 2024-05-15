class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size(); 
        int index =  1 ;

        for(int i  = index ; i >= 1 ;i/=2){
            while( index + i < size && arr[index+i] > arr[index - 1 + i]) index +=i;
        }

        return index;
    }
};