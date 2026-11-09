class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        down = []
        equal = []
        up = []

        for num in nums:
            if num < pivot:
                down.append(num)
            elif num == pivot:
                equal.append(num)
            else:
                up.append(num)

        return down + equal + up