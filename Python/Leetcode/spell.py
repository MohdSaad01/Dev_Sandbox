class Solution:
    def subarraysDivByK(self, nums: list[int], k: int) -> int:
        total = 0
        count = 0
        remainder_count = {0: 1}

        for num in nums:
            total += num
            remainder = total % k

            if remainder in remainder_count:
                count += remainder_count[remainder]

            remainder_count[remainder] = remainder_count.get(remainder, 0) + 1

        return count