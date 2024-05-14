class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();

        if(n > m ) return intersection(nums2, nums1);

        sort(nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        
        vector<int>res;

        for(int j = 0 ; j < n ; j++){
            if(j > 0  && nums1[j-1] == nums1[j]) continue;
            int index = 0,  x = nums1[j];

            for(int i = m ;i>=1; i/=2){
                while(index + i < m  && nums2[index + i] <= x) index+=i;
            }

            if(nums2[index] == x){
                res.emplace_back(x);
            }
        }

        return res;
    }
};