import heapq


class Solution:
    def kthSmallest(self, matrix: list[list[int]], k: int) -> int:
        n = len(matrix)
        heap = []

        for i in range(n):
            heapq.heappush(heap, (matrix[i][0], i, 0))

        for _ in range(k):
            value, r, c = heapq.heappop(heap)

            if _ == k - 1:
                return value

            if c + 1 < n:
                heapq.heappush(heap, (matrix[r][c + 1], r, c + 1))

