/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size(), left=0, right=n-1;
        while(left<right){
            int mid = left + (right-left)>>1;
            if(nums[right]<=nums[mid]){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return right;
    }
};
// @lc code=end

