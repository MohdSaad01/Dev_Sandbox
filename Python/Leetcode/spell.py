class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        current = 0
        count = 0
        lookup = {0:1}

        for num in nums:
            current += num
            freq = lookup.get(current - k, 0)
            count += freq
            lookup[current] = lookup.get(current, 0) + 1
        return count
