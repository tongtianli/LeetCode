#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#
# https://leetcode.com/problems/3sum/description/
#
# algorithms
# Medium (30.18%)
# Likes:    18402
# Dislikes: 1771
# Total Accepted:    2M
# Total Submissions: 6.4M
# Testcase Example:  '[-1,0,1,2,-1,-4]'
#
# Given an integer array nums, return all the triplets [nums[i], nums[j],
# nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
# nums[k] == 0.
# 
# Notice that the solution set must not contain duplicate triplets.
# 
# 
# Example 1:
# Input: nums = [-1,0,1,2,-1,-4]
# Output: [[-1,-1,2],[-1,0,1]]
# Example 2:
# Input: nums = []
# Output: []
# Example 3:
# Input: nums = [0]
# Output: []
# 
# 
# Constraints:
# 
# 
# 0 <= nums.length <= 3000
# -10^5 <= nums[i] <= 10^5
# 
# 
#

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()

        res = []
        if n<3:
            return res

        i = 0

        while i<n-2:
            # inner loop
            t = -nums[i]
            j, k = i+1, n-1
            while j<k:
                
                if nums[j]+nums[k] < t:
                    j += 1
                elif nums[j]+nums[k] > t:
                    k -= 1
                else:
                    res.append([nums[i], nums[j], nums[k]])
                    while j<k and nums[j]==nums[j+1]:
                        j += 1
                    while j<k and nums[k-1]==nums[k]:
                        k -= 1 
                    j, k = j+1, k-1
                    
            while (i<n-2) and  nums[i]==nums[i+1]:
                i += 1
            i += 1

        return res
# @lc code=end

