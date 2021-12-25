/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    void expend(const string &s, int l, int r, int &start, int &maxLen, int n){
        while(l>-1 && r<n && s[l]==s[r]){
            if(r-l>maxLen){
                start = l;
                maxLen = (r-l);
            }

            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0, n = s.length();
        for(int i=0;i<n;i++){
            expend(s, i, i, start, maxLen, n);
            expend(s, i, i+1, start, maxLen, n);
        }
        return s.substr(start, maxLen+1);
    }
};
// @lc code=end

