class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        st = set()
        (low, high , size) = (0,0 , len(s))
        res = 0

        while high < size:
            while s[high] in st:
                st.remove(s[low])
                low += 1
            st.add(s[high])
            res = max(res, high - low+1)
            high+=1

        return res
        