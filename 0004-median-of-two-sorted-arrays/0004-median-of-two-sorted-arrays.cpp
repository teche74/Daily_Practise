class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size() , size2= nums2.size() , total_size = size1 + size2;

        int i = 0 , j = 0, first = 0 , second = 0;

        for(int k = 0 ; k <= (total_size >> 1) ; k++){
            first = second;
            if(i < size1 && j < size2){
                if(nums1[i]  <= nums2[j]){
                    second = nums1[i++];
                }
                else{
                    second = nums2[j++];
                }
            }
            else if(i < size1){
                second = nums1[i++];
            }
            else{
                second = nums2[j++];
            }
        }

        if(total_size & 1){
            return second;
        }

        return (first + second)/2.0;
    }
};