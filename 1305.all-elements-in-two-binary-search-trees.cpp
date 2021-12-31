/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
 *
 * https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
 *
 * algorithms
 * Medium (78.61%)
 * Likes:    1348
 * Dislikes: 47
 * Total Accepted:    109.9K
 * Total Submissions: 139.9K
 * Testcase Example:  '[2,1,4]\n[1,0,3]'
 *
 * Given two binary search trees root1 and root2, return a list containing all
 * the integers from both trees sorted in ascending order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root1 = [2,1,4], root2 = [1,0,3]
 * Output: [0,1,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root1 = [1,null,8], root2 = [8,1]
 * Output: [1,1,8,8]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each tree is in the range [0, 5000].
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(vector<int> &result, TreeNode *root){
        if(!root) return;
        
        inorder(result, root->left);
        result.push_back(root->val);
        inorder(result, root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2, res;
        inorder(list1, root1);
        inorder(list2, root2);
        
        merge(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(res));
        return res;
    }
};
// @lc code=end

