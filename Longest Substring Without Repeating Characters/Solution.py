class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        longest_str = 0
        non_repeats = []

        while i < len(s):
            if s[i] in non_repeats:
                non_repeats = non_repeats[non_repeats.index(s[i])+ 1:]
            non_repeats.append(s[i])

            if len(non_repeats) > longest_str:
                longest_str = len(non_repeats)
            
            i += 1
        
        return longest_str
        