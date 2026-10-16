class Solution:
    def smallestDistancePair(self, nums: list[int], k: int) -> int:
        distances = []
        
        for i in range(len(nums)):
            for j in range(i+1 , len(nums)):
                distance = abs(nums[i] - nums[j])
                distances.append(distance)
                
        distances.sort()
        return distances[k-1]
        