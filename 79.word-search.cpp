/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (39.15%)
 * Likes:    7940
 * Dislikes: 302
 * Total Accepted:    843.3K
 * Total Submissions: 2.2M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 * 
 * 
 * 
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 * 
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(exist(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }

    bool existR(vector<vector<char>> &board, const string &word, int i, int j, int k){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[k]) return false;
        if(k==word.length()-1) return true;

        board[i][j] -= 65;  // Any non-letter char is ok

        bool res=false;
        res |= existR(board, word, i+1, j, k+1);
        res |= existR(board, word, i, j+1, k+1);
        res |= existR(board, word, i-1, j, k+1);
        res |= existR(board, word, i, j-1, k+1);

        board[i][j] += 65;

        return res;
    }
};
// @lc code=end

