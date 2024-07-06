class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();

        int prev = 0 ,  curr = 0 , i =0 , j =0; 

        for(int count = 0 ; count<= size/2 ; count++){
            prev = curr;

            if(i < nums1.size()  && j < nums2.size()){
                if(nums1[i] <= nums2[j]){
                    curr = nums1[i++];
                }
                else{
                    curr = nums2[j++];
                }
            }
            else if( i < nums1.size()){
                curr = nums1[i++];
            }
            else{
                curr = nums2[j++];
            }
        }

        if(!(size & 1)){
            return (prev + curr)/2.0;
        }
        return curr;
    }
};