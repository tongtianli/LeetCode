#
# @lc app=leetcode id=539 lang=python3
#
# [539] Minimum Time Difference
#
# https://leetcode.com/problems/minimum-time-difference/description/
#
# algorithms
# Medium (53.05%)
# Likes:    834
# Dislikes: 186
# Total Accepted:    70.1K
# Total Submissions: 132.1K
# Testcase Example:  '["23:59","00:00"]'
#
# Given a list of 24-hour clock time points in "HH:MM" format, return the
# minimum minutes difference between any two time-points in the list.
# 
# Example 1:
# Input: timePoints = ["23:59","00:00"]
# Output: 1
# Example 2:
# Input: timePoints = ["00:00","23:59","00:00"]
# Output: 0
# 
# 
# Constraints:
# 
# 
# 2 <= timePoints <= 2 * 10^4
# timePoints[i] is in the format "HH:MM".
# 
# 
#

# @lc code=start
class Solution:
    def timeValueOf(self, timeStr: str) -> int:
        nums = timeStr.split(':')
        return int(nums[0])*60 + int(nums[1])
        
    def findMinDifference(self, timePoints: List[str]) -> int:
        timeVals = [ self.timeValueOf(x) for x in timePoints ]
        timeVals = sorted(timeVals)
        last = timeVals[-1]
        res = 24*60
        for i, val in enumerate(timeVals):
            diff = res+val-last if i==0 else val-last
            res = min(diff, res)
            last = val
        return res   
# @lc code=end

