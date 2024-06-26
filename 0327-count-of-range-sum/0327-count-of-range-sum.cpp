class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int size  = nums.size();

        vector<long long >pre(size+1,0);

        for(int i = 0 ;i < size; i++){
            pre[i+1] = pre[i]  + nums[i];
        }


        function<int(int,int)> merge = [&](int left , int right){
            if(right - left <= 1) return 0;


            int mid = left + (right - left)/2;

            int count  = merge(left, mid) + merge(mid, right);

            int m = mid, n  = mid, t = mid, k = 0;
            vector<long>temp(right-left);

            for(int i =left; i<mid; i++){
                while(m < right && pre[m] - pre[i] < lower) m++;
                while(n < right && pre[n] - pre[i] <= upper) n++;
                while(t < right && pre[t] < pre[i] ) temp[k++] = pre[t++];
                temp[k++] = pre[i];
                count += n - m;
            }

            copy(temp.begin(), temp.begin() + t - left, pre.begin() + left);
            return count;
        };

        return merge(0,size+1);
    }


};