class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        max_prod = nums[0]
        min_prod = nums[0]
        result = nums[0]

        for i in range(1, len(nums)):
            x = nums[i]


            candidates = (x, max_prod * x, min_prod * x)

            max_prod = max(candidates)
            min_prod = min(candidates)

            result = max(max_prod, result)

        return result