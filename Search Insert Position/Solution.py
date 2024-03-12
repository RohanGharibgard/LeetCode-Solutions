class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
          
        i = 0
        end = len(nums) -1
        while i <= end:
            mid = (i + end) // 2
            if nums[mid] < target:
                i = mid + 1
            elif nums[mid] > target:
                end = mid - 1      
            else:
                return mid
        return i
