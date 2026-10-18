import heapq
from collections import Counter

class Solution:
    def reorganizeString(self, s: str) -> str:
        freq = Counter(s)
        heap = [(-count, char) for char, count in freq.items()]
        heapq.heapify(heap)

        result = []
        prev_count = 0
        prev_char = ""

        while heap:
            count, char = heapq.heappop(heap)
            result.append(char)

            if prev_count < 0:
                heapq.heappush(heap, (prev_count, prev_char))

            count += 1
            prev_count = count
            prev_char = char

        ans = "".join(result)

        if len(ans) != len(s):
            return ""

        return ans