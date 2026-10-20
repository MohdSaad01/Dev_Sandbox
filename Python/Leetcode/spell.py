import heapq

class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:

        graph = [[] for _ in range(n + 1)]

        for u, v, w in times:
            graph[u].append((v, w))

        distance = [float('inf')] * (n + 1)
        distance[k] = 0

        heap = [(0, k)]

        while heap:
            time, u = heapq.heappop(heap)

            if time > distance[u]:
                continue

            for v, w in graph[u]:
                new_time = time + w

                if new_time < distance[v]:
                    distance[v] = new_time
                    heapq.heappush(heap, (new_time, v))

        max_time = max(distance[1:])

        if max_time == float('inf'):
            return -1

        return max_time
