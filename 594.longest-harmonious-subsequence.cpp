/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 *
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (52.26%)
 * Likes:    1420
 * Dislikes: 144
 * Total Accepted:    109.2K
 * Total Submissions: 208.8K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * We define a harmonious array as an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 * 
 * Given an integer array nums, return the length of its longest harmonious
 * subsequence among all its possible subsequences.
 * 
 * A subsequence of array is a sequence that can be derived from the array by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,1,1,1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res=0;
        unordered_map<int, int> m;
        for(int &num: nums){
            m[num]++;
            if(m.count(num-1)){
                res = max(res, m[num-1]+m[num]);
            }
            if(m.count(num+1)){
                res = max(res, m[num+1]+m[num]);
            }
        }
        return res;
    }
};
// @lc code=end

