class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:

        def solve(L, M):
            n = len(nums)

            prefix = [0] * (n + 1)

            for i in range(n):
                prefix[i + 1] = prefix[i] + nums[i]

            maxL = 0
            ans = 0

            for i in range(L + M, n + 1):

                leftSum = prefix[i - M] - prefix[i - M - L]
                maxL = max(maxL, leftSum)

                rightSum = prefix[i] - prefix[i - M]

                ans = max(ans, maxL + rightSum)

            return ans

        return max(
            solve(firstLen, secondLen),
            solve(secondLen, firstLen)
        )
