/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (41.11%)
 * Likes:    3944
 * Dislikes: 260
 * Total Accepted:    251.7K
 * Total Submissions: 611.7K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,2,3]
 * Output: [3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1]
 * Output: [1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2]
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 * 
 * Follow up: Could you solve the problem in linear time and in O(1) space?
 * 
 */

// @lc code=start
// 71.93% 12.13%
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnts;
        int target = nums.size() / 3;
        vector<int> res;
        
        for(auto &num: nums){
            cnts[num]++;
        }
        
        for(auto &each: cnts){
            if(each.second>target){
                res.push_back(each.first);
            }
        }
        
        return res;
    }
};
// @lc code=end

