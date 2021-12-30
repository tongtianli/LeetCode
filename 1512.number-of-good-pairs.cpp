/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 *
 * https://leetcode.com/problems/number-of-good-pairs/description/
 *
 * algorithms
 * Easy (87.71%)
 * Likes:    1950
 * Dislikes: 127
 * Total Accepted:    247.3K
 * Total Submissions: 281.9K
 * Testcase Example:  '[1,2,3,1,1,3]'
 *
 * Given an array of integers nums, return the number of good pairs.
 * 
 * A pair (i, j) is called good if nums[i] == nums[j] and i < j.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1,1,3]
 * Output: 4
 * Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,1,1,1]
 * Output: 6
 * Explanation: Each pair in the array are good.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: 0
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
    int numIdenticalPairs(vector<int>& nums) {
        map<int, vector<int>> cnts;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            cnts[nums[i]].push_back(i);
        }
        
        for(auto &cnt: cnts){
            int num = cnt.second.size();
            if(num>1){
                res += ((num*(num-1)) / 2);
            }
        }
        
        return res;
    }
};
// @lc code=end

