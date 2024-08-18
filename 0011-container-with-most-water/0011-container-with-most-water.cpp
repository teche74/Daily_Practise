class Solution {
public:
    int maxArea(vector<int>& cont) {
        int size = cont.size();
        int res = 0 ;

        int low = 0 , high = cont.size()-1;

        while(low < high){
            int hght = min(cont[low] , cont[high]);
            int len = high - low;

            res= max(res, hght * len);

            if(cont[low] < cont[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return res;
    }
};