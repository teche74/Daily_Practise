class Solution(object):

    def expand(self, s ,low, high):
        while low >= 0 and high < len(s) and s[low] == s[high]:
            low -= 1
            high +=1

        return high - low - 1 

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        size = len(s)
        index = 0 
        length = 1

        for i  in range(0 , size):
            size1 = self.expand(s , i,i)
            size2 = self.expand(s , i,i+1)

            max_size = max(size1, size2)

            if max_size > length:
                length = max_size
                index = i - (length - 1) // 2 

        return s[index : index + length]


        