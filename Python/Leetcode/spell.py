class Solution:
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        n = len(points)
        visited = [False] * n
        minimum_distance = [float('inf')] * n

        minimum_distance[0] = 0
        total_cost = 0

        for _ in range(n):
            u = -1

            for i in range(n):
                if not visited[i] and (u == -1 or minimum_distance[i] < minimum_distance[u]):
                    u = i

            visited[u] = True
            total_cost += minimum_distance[u]

            x1, y1 = points[u]

            for v in range(n):
                if not visited[v]:
                    x2, y2 = points[v]

                    distance = abs(x1 - x2) + abs(y1 - y2)

                    if distance < minimum_distance[v]:
                        minimum_distance[v] = distance

        return total_cost
