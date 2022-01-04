/*
 * @lc app=leetcode id=378 lang=java
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (58.78%)
 * Likes:    5129
 * Dislikes: 219
 * Total Accepted:    343.6K
 * Total Submissions: 583.9K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given an n x n matrix where each of the rows and columns is sorted in
 * ascending order, return the k^th smallest element in the matrix.
 * 
 * Note that it is the k^th smallest element in the sorted order, not the k^th
 * distinct element.
 * 
 * You must find a solution with a memory complexity better than O(n^2).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * Output: 13
 * Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and
 * the 8^th smallest number is 13
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[-5]], k = 1
 * Output: -5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * All the rows and columns of matrix are guaranteed to be sorted in
 * non-decreasing order.
 * 1 <= k <= n^2
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you solve the problem with a constant memory (i.e., O(1) memory
 * complexity)?
 * Could you solve the problem in O(n) time complexity? The solution may be too
 * advanced for an interview but you may find reading this paper fun.
 * 
 * 
 */

// @lc code=start
class Solution {
    private int binaryLTE(int[] arr, int target){
        int l=0, r=arr.length-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
    
    // Count how many values are absolutely less than num
    private int countSmaller(int[][] matrix, int num){
        int res = 0;
        for(int[] row: matrix){
            int i = binaryLTE(row, num);
            if(i<0) break;
            res += i+1;
        }
        return res;
    }
    
    public int kthSmallest(int[][] matrix, int k) {
        int n=matrix.length;
        int l=matrix[0][0], r=matrix[n-1][n-1];
        // Find leftmost value whose countSmaller>k-1 (the k-smallest value in the matrix)
        while(l<=r){
            int mid = l+(r-l)/2;
            int cnt = countSmaller(matrix, mid);
            if(cnt <= k-1){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l;
    }
}
// @lc code=end

