from typing import List



class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        len_list = len(colors)
        i = 0  
        alternating_groups = 0

        i_limit = len_list - 2 + k
        while i < i_limit:
            alternating_count = i - 1
            while i < i_limit and colors[i % len_list] ^ colors[(i + 1) % len_list]:
                i += 1
            alternating_count = i - alternating_count
            if alternating_count >= k:
                alternating_groups += alternating_count - k + 1
            i += 1
        return alternating_groups

s = Solution()

print(s.numberOfAlternatingGroups([1, 0, 1, 0, 1, 0], 3))
