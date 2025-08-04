class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        size1 = len(nums1)
        size2 = len(nums2)
        total = len(nums1) + len(nums2)

        index1 = 0 
        index2 = 0
        val1 = 0
        val2 = 0 

        for _ in range(0 , (total >> 1) + 1 , 1):
            val1 = val2
            if index1 < size1 and index2 < size2:
                if nums1[index1] <= nums2[index2]:
                    val2 = nums1[index1]
                    index1 += 1
                else:
                    val2 = nums2[index2]
                    index2 += 1
            elif index1 < size1:
                val2 = nums1[index1]
                index1 += 1
            else:
                val2 = nums2[index2]
                index2 += 1
        

        if total % 2 == 0 :
            return (val1 + val2)/ 2.0
        return val2
