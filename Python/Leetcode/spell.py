class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        left = 0
        right = 0
        total = 0
        max_sum = None

        while right < len(nums):

            total += nums[right]
            right += 1

            if (right - left) == k:
                if max_sum is None:
                    max_sum = total
                else:
                    max_sum = max(max_sum, total)
                total -= nums[left]
                left += 1

        return max_sum / k
