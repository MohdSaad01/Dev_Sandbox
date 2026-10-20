
from collections import deque

class Solution:
    def findOrder(self,numCourses: int,prerequisites: list[list[int]]) -> list[int]:

        graph = [[] for _ in range(numCourses)]
        degree = [0] * numCourses

        for course, prerequisite in prerequisites:
            graph[prerequisite].append(course)
            degree[course] += 1

        queue = deque()

        for course in range(numCourses):
            if degree[course] == 0:
                queue.append(course)

        order = []

        while queue:
            course = queue.popleft()
            order.append(course)

            for neighbor in graph[course]:
                degree[neighbor] -= 1

                if degree[neighbor] == 0:
                    queue.append(neighbor)

        if len(order) != numCourses:
            return []

        return order
