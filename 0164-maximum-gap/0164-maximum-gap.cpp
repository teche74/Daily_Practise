class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();

        if(size < 2 ) return 0;

        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(), nums.end());


        int gap = max(1,(maxi - mini)/(size-1));
        int buckets  = (maxi - mini)/gap + 1 ;

        vector<int>max_e(buckets,INT_MIN);
        vector<int>min_e(buckets,INT_MAX);

        for(int num : nums){
            int id = (num - mini)/gap;
            min_e[id] = min(min_e[id],num);
            max_e[id] = max(max_e[id],num);
        }


        int ans = 0, prev = mini;
        for (int i = 0; i < buckets; ++i) {
            if (min_e[i] == INT_MAX) continue; 
            ans = max(ans, min_e[i] - prev);
            prev = max_e[i];
        }

        return ans;

    }
};