class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i =0 , j =0 , m = nums1.size() , n = nums2.size() ;

        vector<int>res;

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                res.emplace_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};