class Solution:
    def firstMissingPositive(self, nums):
        n = len(nums)

        # Place each number in its correct position
        for i in range(n):
            while (
                1 <= nums[i] <= n and
                nums[nums[i] - 1] != nums[i]
            ):
                correct = nums[i] - 1
                nums[i], nums[correct] = nums[correct], nums[i]

        # Find the first missing positive
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1

        return n + 1
