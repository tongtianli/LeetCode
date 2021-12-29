/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (61.73%)
 * Likes:    7432
 * Dislikes: 300
 * Total Accepted:    1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array nums of size n, return the majority element.
 * 
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 * 
 * 
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num=nums[0], cnt=1, n=nums.size();
        for(int i=1;i<n;i++){
            if(cnt==0){
                num=nums[i];
            }
            if(nums[i]==num) cnt++;
            else cnt--;
        }
        return num;
    }
};
// @lc code=end

