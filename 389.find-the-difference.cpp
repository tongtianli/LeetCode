/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 *
 * https://leetcode.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (58.96%)
 * Likes:    1739
 * Dislikes: 340
 * Total Accepted:    302.2K
 * Total Submissions: 512.5K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * You are given two strings s and t.
 * 
 * String t is generated by random shuffling string s and then add one more
 * letter at a random position.
 * 
 * Return the letter that was added to t.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcd", t = "abcde"
 * Output: "e"
 * Explanation: 'e' is the letter that was added.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "", t = "y"
 * Output: "y"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 1000
 * t.length == s.length + 1
 * s and t consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res=0;
        
        for(char &ch: s) res ^= ch;
        for(char &ch: t) res ^= ch;
        
        return res;
    }
};
// @lc code=end

