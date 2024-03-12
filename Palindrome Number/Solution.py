class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        palindrome = 0
        c = x
        while x > 0:
            palindrome = palindrome * 10 +(x%10)
            x /= 10
        return palindrome == c

