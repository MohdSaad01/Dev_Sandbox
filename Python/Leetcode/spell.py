class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0

        left = 0
        multiply = 1
        counter = 0

        for right in range(len(nums)):
            multiply *= nums[right]

            while multiply >= k:
                multiply //= nums[left]
                left += 1

            counter += right - left + 1

        return counter
