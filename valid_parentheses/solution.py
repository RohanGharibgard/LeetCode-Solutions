class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # ['[', '(', '[']
        pars = []
        for i in range(len(s)):
            c = s[i]
            if c == '('or c == '[' or c == '{':
                pars.append(c)
            elif (len(pars) > 0):
                if c == ')' and '(' == pars[-1] :
                    pars.pop(-1)
                elif c == ']' and '[' == pars[-1]:
                    pars.pop(-1)
                elif c == '}' and '{' == pars[-1] :
                    pars.pop (-1)
                else:
                    return False
            else:
                return False
        return len(pars) == 0
