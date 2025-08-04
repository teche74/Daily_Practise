class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        map = {}

        for index,value in enumerate(nums):
            remain = target - value
            if remain in map:
                return [map[remain] , index]
            map[value] = index
        
        return [-1,-1]