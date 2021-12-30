/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 *
 * https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/
 *
 * algorithms
 * Easy (67.51%)
 * Likes:    394
 * Dislikes: 74
 * Total Accepted:    57K
 * Total Submissions: 84.5K
 * Testcase Example:  '[4000,3000,1000,2000]'
 *
 * You are given an array of unique integers salary where salary[i] is the
 * salary of the i^th employee.
 * 
 * Return the average salary of employees excluding the minimum and maximum
 * salary. Answers within 10^-5 of the actual answer will be accepted.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: salary = [4000,3000,1000,2000]
 * Output: 2500.00000
 * Explanation: Minimum salary and maximum salary are 1000 and 4000
 * respectively.
 * Average salary excluding minimum and maximum salary is (2000+3000) / 2 =
 * 2500
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: salary = [1000,2000,3000]
 * Output: 2000.00000
 * Explanation: Minimum salary and maximum salary are 1000 and 3000
 * respectively.
 * Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= salary.length <= 100
 * 1000 <= salary[i] <= 10^6
 * All the integers of salary are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double average(vector<int>& salary) {
        int M=0, m=1000001, n=salary.size();
        double res=0;
        for(int i=0;i<n;i++){
            int s=salary[i];
            if(s>M) M=s;
            if(s<m) m=s;
            res += s;
        }
        return (res-M-m)/(n-2);
    }
};
// @lc code=end

