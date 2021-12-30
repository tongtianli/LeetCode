/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 *
 * https://leetcode.com/problems/count-the-number-of-consistent-strings/description/
 *
 * algorithms
 * Easy (81.73%)
 * Likes:    647
 * Dislikes: 31
 * Total Accepted:    70.8K
 * Total Submissions: 86.6K
 * Testcase Example:  '"ab"\n["ad","bd","aaab","baa","badab"]'
 *
 * You are given a string allowed consisting of distinct characters and an
 * array of strings words. A string is consistent if all characters in the
 * string appear in the string allowed.
 * 
 * Return the number of consistent strings in the array words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
 * Output: 2
 * Explanation: Strings "aaab" and "baa" are consistent since they only contain
 * characters 'a' and 'b'.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
 * Output: 7
 * Explanation: All strings are consistent.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
 * Output: 4
 * Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 10^4
 * 1 <= allowed.length <=^ 26
 * 1 <= words[i].length <= 10
 * The characters in allowed are distinct.
 * words[i] and allowed contain only lowercase English letters.
 * 
 * 
 */

// @lc code=start
// 24.55% 88.60%
class Solution {
public:
    bool consistAllFrom(const string &refer, string &word){
        sort(word.begin(), word.end());
        
        int i=0, j=0;
        
        while(j<word.length()){
            if(word[j]!=refer[i]){
                i++;
            }else{
                j++;
            }
            if(i==refer.length()){
                return false;
            }
        }
        
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        sort(allowed.begin(), allowed.end());
        
        int res = 0;
        
        for(string &word: words){
            if(consistAllFrom(allowed, word)){
                res++;
            }
        }
        
        return res;
    }
};
// 64.92% 25.13% 
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedChars(allowed.begin(), allowed.end());
        
        int res = 0;
        
        for(string &word: words){
            for(char &ch: word){
                if(!allowedChars.count(ch)){
                    res--;
                    break;
                }
            }
            res++;
        }
        
        return res;
    }
};
// @lc code=end

