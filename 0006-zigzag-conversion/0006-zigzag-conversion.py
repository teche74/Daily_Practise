class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        size = len(s)

        if size <= numRows or numRows == 1:
            return s

        map = [""] * numRows

        index = 0
        direction = 1 

        for char in s:
            map[index] += char
            if index == 0:
                direction = 1
            elif index == numRows - 1:
                direction = -1
            index += direction

        return "".join(map)      