class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or numRows >= len(s):
            return s
        
        rows = [""] * numRows
        index, step = 0, 1
        
        for char in s:
            rows[index] += char
            if index == 0:
                step = 1  # Moving down
            elif index == numRows - 1:
                step = -1  # Moving up
            index += step
        
        return "".join(rows)

# Example usage:
solution = Solution()
print(solution.convert("PAYPALISHIRING", 3)) 
print(solution.convert("PAYPALISHIRING", 4)) 
print(solution.convert("A", 1))