class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:

        ans = []

        while nums:
            temp = sorted(set(nums))

            for num in temp:
                ans.append(num)
                nums.remove(num)
        return ans

nums = [25,27,24,29,1,19,12,29,16,25,11,29,28,27,26,21,1,22,1]
print(Solution().rearrangeArray(nums))