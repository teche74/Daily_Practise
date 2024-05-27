class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size()  + nums2.size() ;

        int first  = 0 , second  = 0 , i =0 , j =0 ;


        for(int count= 0; count <= size /2 ; count++){
            first = second;
            if(i < nums1.size() &&  j< nums2.size()){
                if(nums1[i] < nums2[j]){
                    second = nums1[i++];
                }
                else{
                    second = nums2[j++];
                }
            }
            else if(i < nums1.size()){
                second = nums1[i++];
            }
            else{
                second = nums2[j++];
            }
        }

        if( !(size & 1) ){
            return (first + second)/2.0;
        }
        return second;
    }
};