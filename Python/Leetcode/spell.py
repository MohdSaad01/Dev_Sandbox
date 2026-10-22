class Solution:
    def containsNearbyAlmostDuplicate(self, nums: list[int], indexDiff: int, valueDiff: int) -> bool:
        buckets = {}
        w = valueDiff + 1

        for i, x in enumerate(nums):

            if i > indexDiff:
                old = nums[i - indexDiff - 1]
                del buckets[old // w]

            bucket = x // w

            if bucket in buckets:
                return True

            if bucket - 1 in buckets:
                if abs(x - buckets[bucket - 1]) <= valueDiff:
                    return True

            if bucket + 1 in buckets:
                if abs(x - buckets[bucket + 1]) <= valueDiff:
                    return True

            buckets[bucket] = x

        return False
