/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 *
 * https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/
 *
 * algorithms
 * Easy (51.75%)
 * Likes:    835
 * Dislikes: 72
 * Total Accepted:    48.8K
 * Total Submissions: 94.4K
 * Testcase Example:  '[4,2,3]\n1'
 *
 * Given an integer array nums and an integer k, modify the array in the
 * following way:
 * 
 * 
 * choose an index i and replace nums[i] with -nums[i].
 * 
 * 
 * You should apply this process exactly k times. You may choose the same index
 * i multiple times.
 * 
 * Return the largest possible sum of the array after modifying it in this
 * way.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,2,3], k = 1
 * Output: 5
 * Explanation: Choose index 1 and nums becomes [4,-2,3].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,-1,0,2], k = 3
 * Output: 6
 * Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,-3,-1,5,-4], k = 2
 * Output: 13
 * Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -100 <= nums[i] <= 100
 * 1 <= k <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int i=0, res=0;
        while(i<nums.size() && nums[i]<0 && k>0){
            int val = -nums[i];
            nums[i] = val;
            res += val;
            i++;
            k--;
        }
        
        int small = i>0 ? nums[i-1] : 101;
        if(i<nums.size()) small = min(small, nums[i]);
        
        while(i<nums.size()){
            res += nums[i];
            i++;
        }
        
        if(k%2){
            res -= 2*small;
        }
        
        return res;
        
    }
};
// @lc code=end

