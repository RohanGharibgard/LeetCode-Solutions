class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        sum  = int(a) + int(b)
        i = 1
        while i <= sum:
            sing = (sum / i) % 10 
            if sing >= 2: 
                sum += i *10 - i *2
            i*= 10 
        return str(sum)

