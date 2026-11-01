class Solution:
    def minMoves(self, nums: List[int]) -> int:
        minimumn = min(nums)

        moves = 0
        for num in nums:
            moves += num - minimumn

        return moves