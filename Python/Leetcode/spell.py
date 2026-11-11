class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        stack = []

        for i in range(len(nums)):
            if not stack or nums[i] < nums[stack[-1]]:
                stack.append(i)

        output = 0

        for j in range(len(nums) - 1, -1, -1):
            while stack and nums[stack[-1]] <= nums[j]:
                i = stack.pop()
                output = max(output, j - i)

        return output
