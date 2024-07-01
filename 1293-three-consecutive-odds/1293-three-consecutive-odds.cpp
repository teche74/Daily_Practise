class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int low = 0 , high = 0 , size = arr.size() ;

        while(high < size){
            if(!(arr[high] & 1)){
                low = ++high; 
            }
            if(high - low +1 == 3) return true;
            high++;
        } 
        return false;
    }
};