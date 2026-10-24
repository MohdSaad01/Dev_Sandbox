class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        answer = [0] * len(nums)
        prefix = 1
        answer[0] = prefix

        for i in range(1, len(nums)):
            prefix *= nums[i - 1]
            answer[i] = prefix

        suffix = 1
        for i in range(len(nums) - 1, -1, -1):
            answer[i] *= suffix

            suffix *= nums[i]

        return answer




