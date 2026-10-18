import heapq
from collections import Counter

class Solution:
    def leastInterval(self, tasks: list[str], n: int) -> int:
        freq = Counter(tasks)

        heap = [-count for count in freq.values()]
        heapq.heapify(heap)

        time = 0

        while heap:
            temp = []
            cycle = n + 1

            for _ in range(cycle):
                if heap:
                    count = heapq.heappop(heap)
                    count += 1

                    if count < 0:
                        temp.append(count)
                    time += 1
                else:
                    if temp:
                        time += 1
                    else:
                        break
            for count in temp: 
                heapq.heappush(heap, count)

        return time