class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        maxlength = 0

        for num in num_set:
            if num - 1 not in num_set:
                counter = 1
                curr = num


                while curr + 1 in num_set:
                    counter += 1
                    curr += 1


                maxlength = max(maxlength, counter)

        return maxlength