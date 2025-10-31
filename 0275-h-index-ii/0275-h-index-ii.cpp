class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0 , high = citations.size()-1 , size = citations.size();
        int res = 0;

        while(low <= high){
            int mid = low + ((high - low) >> 1);

            if(citations[mid] >= size - mid){
                res = max(res, size - mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return res;
    }
};