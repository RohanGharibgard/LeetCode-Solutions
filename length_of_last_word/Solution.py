class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        detect = False
        for i in range(len(s)-1,-1, -1):
            if s[i] == " " and not detect:
                count = 0
            elif s[i] != " ":
                count+=1
                detect = True
            elif s[i] == " ":
                return count
        return count

