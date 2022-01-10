/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 *
 * https://leetcode.com/problems/reordered-power-of-2/description/
 *
 * algorithms
 * Medium (61.32%)
 * Likes:    536
 * Dislikes: 164
 * Total Accepted:    39.4K
 * Total Submissions: 64.2K
 * Testcase Example:  '1'
 *
 * You are given an integer n. We reorder the digits in any order (including
 * the original order) such that the leading digit is not zero.
 * 
 * Return true if and only if we can do this so that the resulting number is a
 * power of two.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 10
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string strn = to_string(n);
        sort(strn.begin(), strn.end());
        
        for(int i=1; i<=1000000000; i*=2){
            string stri = to_string(i);
            sort(stri.begin(), stri.end());
            if(strn==stri) return true;
        }
        
        return false;
    }
};
// @lc code=end

