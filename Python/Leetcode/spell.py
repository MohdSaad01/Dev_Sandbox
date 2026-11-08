class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1 = set(nums1)
        set2 = set(nums2)

        first = []
        second = []

        for x in set1:
            if x not in set2:
                first.append(x)

        for x in set2:
            if x not in set1:
                second.append(x)

        return [first, second]
