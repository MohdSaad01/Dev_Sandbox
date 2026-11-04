
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        total_sum = 0

        curr_max = 0
        max_sum = float('-inf')

        curr = 0
        minimum = float('inf')

        for num in nums:
            total_sum += num

            curr_max = max(num, curr_max + num)
            max_sum = max(max_sum, curr_max)

            curr = min(num, curr + num)
            minimum = min(minimum, curr)

        if max_sum < 0:
            return max_sum

        return max(max_sum, total_sum - minimum)
