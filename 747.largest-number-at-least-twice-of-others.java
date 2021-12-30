/*
 * @lc app=leetcode id=747 lang=java
 *
 * [747] Largest Number At Least Twice of Others
 *
 * https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
 *
 * algorithms
 * Easy (44.50%)
 * Likes:    579
 * Dislikes: 722
 * Total Accepted:    139.5K
 * Total Submissions: 313.3K
 * Testcase Example:  '[3,6,1,0]'
 *
 * You are given an integer array nums where the largest integer is unique.
 * 
 * Determine whether the largest element in the array is at least twice as much
 * as every other number in the array. If it is, return the index of the
 * largest element, or return -1 otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,6,1,0]
 * Output: 1
 * Explanation: 6 is the largest integer.
 * For every other number in the array x, 6 is at least twice as big as x.
 * The index of value 6 is 1, so we return 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4]
 * Output: -1
 * Explanation: 4 is less than twice the value of 3, so we return -1.
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1]
 * Output: 0
 * Explanation: 1 is trivially at least twice the value as any other number
 * because there are no other numbers.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 50
 * 0 <= nums[i] <= 100
 * The largest element in nums is unique.
 * 
 * 
 */

// @lc code=start
class Solution {
    public int dominantIndex(int[] nums) {
        Integer secondLargeIndex = null;
        int largestIndex = 0;
        
        for(int i=1;i<nums.length;i++){
            if(nums[i]>nums[largestIndex]){
                secondLargeIndex = largestIndex;
                largestIndex = i;
            }else if(secondLargeIndex == null || nums[i]>nums[secondLargeIndex]){
                secondLargeIndex = i;
            }
        }
        if(secondLargeIndex == null){
            return 0;
        }
        if(nums[largestIndex] >= 2*nums[secondLargeIndex]){
            return largestIndex;
        }
        return -1;
    }
}
// @lc code=end

