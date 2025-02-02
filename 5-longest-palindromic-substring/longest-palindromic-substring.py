class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        def expand_around_center(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            # Return the longest palindrome found
            return s[left + 1:right]
        
        longest = ""
        for i in range(len(s)):
            # Odd length palindrome (centered at a single character)
            palindrome1 = expand_around_center(i, i)
            # Even length palindrome (centered between two characters)
            palindrome2 = expand_around_center(i, i + 1)
            
            # Update the longest palindrome found
            if len(palindrome1) > len(longest):
                longest = palindrome1
            if len(palindrome2) > len(longest):
                longest = palindrome2
        
        return longest