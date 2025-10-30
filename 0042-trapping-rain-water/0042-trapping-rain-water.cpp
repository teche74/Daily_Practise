class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int>max_left(size , 0) , max_right(size, 0);

        max_left[0] = height[0] , max_right[size - 1] = height[size-1];

        for(int i = 1 ; i < size ; i++){
            max_left[i] = max(max_left[i-1] , height[i]);
            max_right[size-i-1] = max(max_right[size-i] , height[size-i-1]);
        }

        int res = 0;

        for(int i = 1 ; i < size-1; i++){
            res += min(max_left[i] , max_right[i]) - height[i];
        }

        return res;
    }
};