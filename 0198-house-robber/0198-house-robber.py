class Solution:
    def rob(self, nums: list[int]) -> int:
        # Traverse list once find addition for odd and even placed numbers
        # Compare and return largest number
        odd = 0
        oddIdx = 1
        even = 0
        evenIdx = 0

        while oddIdx < len(nums) or evenIdx < len(nums):
            if oddIdx < len(nums):
                odd = odd + nums[oddIdx]
                oddIdx += 2

            if evenIdx < len(nums):
                even = even + nums[evenIdx]
                evenIdx += 2
            
        if odd > even:
            return odd
        else:
            return even

