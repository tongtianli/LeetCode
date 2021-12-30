/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 *
 * https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/
 *
 * algorithms
 * Easy (81.58%)
 * Likes:    524
 * Dislikes: 11
 * Total Accepted:    63.4K
 * Total Submissions: 77.7K
 * Testcase Example:  '"thequickbrownfoxjumpsoverthelazydog"'
 *
 * A pangram is a sentence where every letter of the English alphabet appears
 * at least once.
 * 
 * Given a string sentence containing only lowercase English letters, return
 * true if sentence is a pangram, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
 * Output: true
 * Explanation: sentence contains at least one of every letter of the English
 * alphabet.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: sentence = "leetcode"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= sentence.length <= 1000
 * sentence consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int res=0;
        for(char &ch: sentence){
            res |= 1<<(ch-'a');
        }
        return res==67108863; // 26 '1' bits
    }
};
// @lc code=end

