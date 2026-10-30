class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        # nums = [1,3,4,2,2]

        slow = 0
        fast = 0

        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]

            if slow == fast:
                break

        slow = 0

        while True:
            slow = nums[slow]
            fast = nums[fast]

            if slow == fast:
                return slow

