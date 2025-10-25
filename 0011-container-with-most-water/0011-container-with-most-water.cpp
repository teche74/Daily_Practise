class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();

        int low = 0 , high = size-1 , res = 0;

        while(low < high){
            int h = (high - low) * min(height[low] , height[high]);

            res = max(res , h);

            if(height[low] <= height[high]){
                low++;
            }
            else{
                high--;
            }
        } 

        return res;
    }
};