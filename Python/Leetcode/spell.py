class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        fullgas = 0
        nowgas = 0
        run = 0

        for i in range(len(gas)):
            fullgas += gas[i] - cost[i]
            nowgas += gas[i] - cost[i]

            if nowgas < 0:
                run = i + 1
                nowgas = 0

        return run if fullgas >= 0 else -1
