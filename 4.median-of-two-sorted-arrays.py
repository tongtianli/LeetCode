#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#
# https://leetcode.com/problems/median-of-two-sorted-arrays/description/
#
# algorithms
# Hard (33.27%)
# Likes:    13994
# Dislikes: 1795
# Total Accepted:    1.2M
# Total Submissions: 3.6M
# Testcase Example:  '[1,3]\n[2]'
#
# Given two sorted arrays nums1 and nums2 of size m and n respectively, return
# the median of the two sorted arrays.
# 
# The overall run time complexity should be O(log (m+n)).
# 
# 
# Example 1:
# 
# 
# Input: nums1 = [1,3], nums2 = [2]
# Output: 2.00000
# Explanation: merged array = [1,2,3] and median is 2.
# 
# 
# Example 2:
# 
# 
# Input: nums1 = [1,2], nums2 = [3,4]
# Output: 2.50000
# Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
# 
# 
# 
# Constraints:
# 
# 
# nums1.length == m
# nums2.length == n
# 0 <= m <= 1000
# 0 <= n <= 1000
# 1 <= m + n <= 2000
# -10^6 <= nums1[i], nums2[i] <= 10^6
# 
# 
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        limit = 1000001
        total = len(nums1) + len(nums2)
        half = total // 2
        A, B = nums1, nums2
        if len(A) > len(B):
            A, B = B, A
            
        l, r = 0, len(A)-1
        
        while True:
            i = (l+r) // 2
            j = half - i - 2
            
            Aleft = A[i] if i>=0 else -limit
            Aright = A[i+1] if i+1<len(A) else limit
            Bleft = B[j] if j>=0 else -limit
            Bright = B[j+1] if j+1<len(B) else limit
            
            if Aleft > Bright:
                r = i-1
            elif Bleft > Aright:
                l = i+1
            else:
                if total % 2:
                    return min(Aright, Bright)
                else:
                    return (max(Aleft, Bleft)+min(Aright, Bright))/2
            
# @lc code=end

