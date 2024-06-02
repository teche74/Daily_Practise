class Solution {
public:
    int numIdenticalPairs(vector<int>& arr) {
        int size = arr.size(), count =0;

        for(int i =0; i <size; i++){
            for(int j = i+1; j< size ; j++){
                if(arr[i] == arr[j]){
                    count++;
                }
            }
        }
        return count;
    }
};