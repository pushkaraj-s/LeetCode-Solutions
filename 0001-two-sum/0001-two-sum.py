class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i in range(len(nums)):
            check = target - nums[i]
            for j in range(i+1, len(nums)):
                if nums[j] == check:
                    return [i, j]
            