class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        triplet = []
        n = len(nums)
        seen = set()

        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1 , n):
                    mylist = sorted([nums[i], nums[j], nums[k]])
                    if nums[i] + nums[j] + nums[k] == 0 and tuple(mylist) not in seen:
                        triplet.append(mylist)
                        seen.add(tuple(mylist))
        return triplet
