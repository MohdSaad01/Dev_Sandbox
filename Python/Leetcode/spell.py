class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        left = 0
        right = 1

        while right < len(nums):
            if nums[left] == nums[right]:
                right += 1
            else:
                left += 1
                nums[left] = nums[right]

        return left + 1
