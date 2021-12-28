/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (51.90%)
 * Likes:    3969
 * Dislikes: 129
 * Total Accepted:    439.9K
 * Total Submissions: 847.2K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> results;
        
        sort(nums.begin(), nums.end());
        addSubset(results, subset, nums, 0);
        
        return results;
    }
    
    void addSubset(vector<vector<int>> &results, vector<int> &subset, const vector<int> &nums, int startIndex){
        results.push_back(subset);
        
        for(int i=startIndex; i<nums.size(); i++){
            if(i!=startIndex && nums[i]==nums[i-1]) continue;
            
            subset.push_back(nums[i]);
            addSubset(results, subset, nums, i+1);
            subset.pop_back();
        }
    }
};
// @lc code=end

