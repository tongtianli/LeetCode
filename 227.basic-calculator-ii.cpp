/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (40.33%)
 * Likes:    3602
 * Dislikes: 485
 * Total Accepted:    359.2K
 * Total Submissions: 883.5K
 * Testcase Example:  '"3+2*2"'
 *
 * Given a string s which represents an expression, evaluate this expression
 * and return its value. 
 * 
 * The integer division should truncate toward zero.
 * 
 * You may assume that the given expression is always valid. All intermediate
 * results will be in the range of [-2^31, 2^31 - 1].
 * 
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 * 
 * 
 * Example 1:
 * Input: s = "3+2*2"
 * Output: 7
 * Example 2:
 * Input: s = " 3/2 "
 * Output: 1
 * Example 3:
 * Input: s = " 3+5 / 2 "
 * Output: 5
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s consists of integers and operators ('+', '-', '*', '/') separated by some
 * number of spaces.
 * s represents a valid expression.
 * All the integers in the expression are non-negative integers in the range
 * [0, 2^31 - 1].
 * The answer is guaranteed to fit in a 32-bit integer.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int nextInt(const string &s, int &i, int n){
        while(i<n && s[i]==' ') i++;
        int res = 0;
        while(i<n && s[i]>='0' && s[i]<='9'){
            res = res*10 + (s[i]-'0');
            i++;
        }
        return res;
    }
    char nextOperator(const string &s, int &i, int n){
        while(i<n && s[i]==' ') i++;
        return s[i++];
    }
    bool hasNext(const string &s, int i, int n){
        while(i<n){
            if(i<n && s[i]==' ') i++;
            else return true;
        }
        return false;
    }
    int calculate(string s) {
        int i=0, n=s.length();
        stack<int> nums;
        nums.push(nextInt(s, i, n));
        while(hasNext(s, i, n)){
            char op = nextOperator(s, i, n);
            int other = nextInt(s, i, n);
            if(op=='+'|| op=='-'){
                nums.push(op=='+' ? other : -other);
            }else{
                int num = nums.top();
                nums.pop();
                nums.push(op=='*' ? num*other : num/other);
            }
        }
        int res = 0;
        while(nums.size()){
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};
// @lc code=end

