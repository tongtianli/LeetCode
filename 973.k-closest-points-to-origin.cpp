/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 *
 * https://leetcode.com/problems/k-closest-points-to-origin/description/
 *
 * algorithms
 * Medium (65.76%)
 * Likes:    4611
 * Dislikes: 186
 * Total Accepted:    639.1K
 * Total Submissions: 967.8K
 * Testcase Example:  '[[1,3],[-2,2]]\n1'
 *
 * Given an array of points where points[i] = [xi, yi] represents a point on
 * the X-Y plane and an integer k, return the k closest points to the origin
 * (0, 0).
 * 
 * The distance between two points on the X-Y plane is the Euclidean distance
 * (i.e., √(x1 - x2)^2 + (y1 - y2)^2).
 * 
 * You may return the answer in any order. The answer is guaranteed to be
 * unique (except for the order that it is in).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: points = [[1,3],[-2,2]], k = 1
 * Output: [[-2,2]]
 * Explanation:
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest k = 1 points from the origin, so the answer is just
 * [[-2,2]].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: points = [[3,3],[5,-1],[-2,4]], k = 2
 * Output: [[3,3],[-2,4]]
 * Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= points.length <= 10^4
 * -10^4 < xi, yi < 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return quickSelect(points, k);
    }
    
    vector<vector<int>> quickSelect(vector<vector<int>> &points, int k){
        int left=0, right=points.size()-1, pivot=points.size();
        while(pivot!=k){
            pivot=partition(points, left, right);
            if(pivot<k) left=pivot;
            else right=pivot-1;
        }
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
    
    int partition(vector<vector<int>> &points, int left, int right){
        int mid=left+(right-left)/2;
        int target=distance(points[mid]);
        while(left<right){
            if(distance(points[left])>=target){
                points[left].swap(points[right]);
                right--;
            }else{
                left++;
            }
        }
        if(distance(points[left])<target) left++;
        return left;
    }
    
    int distance(vector<int> &point){
        return point[0]*point[0] + point[1]*point[1];
    }
};
// @lc code=end

