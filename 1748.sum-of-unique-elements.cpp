/*
 * @lc app=leetcode id=1748 lang=cpp
 *
 * [1748] Sum of Unique Elements
 *
 * https://leetcode.com/problems/sum-of-unique-elements/description/
 *
 * algorithms
 * Easy (75.17%)
 * Likes:    585
 * Dislikes: 15
 * Total Accepted:    60.6K
 * Total Submissions: 80.6K
 * Testcase Example:  '[1,2,3,2]'
 *
 * You are given an integer array nums. The unique elements of an array are the
 * elements that appear exactly once in the array.
 * 
 * Return the sum of all the unique elements of nums.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,2]
 * Output: 4
 * Explanation: The unique elements are [1,3], and the sum is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,1,1,1,1]
 * Output: 0
 * Explanation: There are no unique elements, and the sum is 0.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,4,5]
 * Output: 15
 * Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> cnts(101);
        for(int &num: nums){
            cnts[num]++;
        }
        int res=0;
        for(int i=1;i<=100; i++){
            if(cnts[i]==1) res+=i;
        }
        return res;
    }
};
// @lc code=end

