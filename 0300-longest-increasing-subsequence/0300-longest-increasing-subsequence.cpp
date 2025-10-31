class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;

        function<int(int)> found = [&](int val){
            int low = 0 , high = res.size()-1 , index = -1;
            
            while(low <= high){
                int mid = low + ((high - low) >> 1);

                if(res[mid] >= val){
                    index = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }

            return index;
        };
        
        for(int x : nums){
            int index = found(x);

            if(res.empty() || index >= res.size()){
                res.push_back(x);
            }
            else if(index != -1){
                res[index] = x;
            }
        }

        return res.size();
    }
};