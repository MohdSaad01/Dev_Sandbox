import heapq


class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: list[list[int]]) -> int:
        heap = []
        prev = 0
        stop = 0

        stations.append([target, 0])

        for pos, fuel in stations:
            startFuel -= pos - prev

            while startFuel < 0:
                if not heap:
                    return -1

                startFuel -= heapq.heappop(heap)
                stop += 1
            heapq.heappush(heap, -fuel)
            prev = pos

        return stop
