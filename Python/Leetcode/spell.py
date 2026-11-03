class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        remainders = {0: -1}
        prefix = 0

        for i, num in enumerate(nums):
            prefix += num
            remainder = prefix % k

            if remainder in remainders:
                if i - remainders[remainder] >= 2:
                    return True
            else:
                remainders[remainder] = i

        return False