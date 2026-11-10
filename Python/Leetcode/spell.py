class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        n = len(nums)
        MOD = 10**9 + 7

        prefix = [0] * (n + 1)

        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        left = [-1] * n
        right = [n] * n

        stack = []

        for i in range(n):
            while stack and nums[stack[-1]] >= nums[i]:
                stack.pop()

            left[i] = stack[-1] if stack else -1
            stack.append(i)

        stack.clear()

        for i in range(n - 1, -1, -1):
            while stack and nums[stack[-1]] >= nums[i]:
                stack.pop()

            right[i] = stack[-1] if stack else n
            stack.append(i)

        ans = 0

        for i in range(n):
            subarray_sum = prefix[right[i]] - prefix[left[i] + 1]

            product = nums[i] * subarray_sum

            ans = max(ans, product)

        return ans % MOD