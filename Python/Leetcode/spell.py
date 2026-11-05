class Solution:
    def jump(self, nums: List[int]) -> int:
        jump = 0
        current = 0
        distance = 0

        for i in range(len(nums) - 1):
            distance = max(distance, i + nums[i])

            if i == current:
                jump += 1
                current = distance

        return jump