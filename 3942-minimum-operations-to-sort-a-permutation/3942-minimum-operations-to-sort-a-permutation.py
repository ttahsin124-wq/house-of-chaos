from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        asc = all(nums[(i + 1) % n] == (nums[i] + 1) % n for i in range(n))
        if asc:
            k = nums[0]
            return min((n - k) % n, k + 2)

        desc = all(nums[(i + 1) % n] == (nums[i] - 1) % n for i in range(n))
        if desc:
            k = (nums[0] + 1) % n
            return min(k + 1, 1 + (n - k) % n)

        return -1