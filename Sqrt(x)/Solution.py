class Solution(object):
    def mySqrt(self, x):
        if x == 0 or x == 1:
            return x

        start = 0
        end = x
        while start <= end:
            mid = ( end + start) // 2
            if (mid * mid > x):
                end = mid - 1
            elif mid * mid < x:
                start = mid + 1

            else:
                return mid
        return end
        
