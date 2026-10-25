from collections import Counter
class Solution:
    def intersect(self, nums1: list[int], nums2: list[int]) -> list[int]:
        counts = Counter(nums1) & Counter(nums2)

        return list(counts.elements())
