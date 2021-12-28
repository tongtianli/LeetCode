/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (56.02%)
 * Likes:    7225
 * Dislikes: 180
 * Total Accepted:    622.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same
 * tree, construct and return the binary tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
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
    int preorderIndex;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        unordered_map<int, int> inorderIndexMap;
        
        for(int i=0;i<inorder.size();i++){
            inorderIndexMap[inorder[i]] = i;
        }
        
        return buildTree(preorder, inorderIndexMap, 0, preorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, unordered_map<int, int> &inorderIndexMap, int start, int end){
        if(start>end) return NULL;
        
        int rootVal = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootVal);
        
        root->left = buildTree(preorder, inorderIndexMap, start, inorderIndexMap[rootVal]-1);
        root->right = buildTree(preorder, inorderIndexMap, inorderIndexMap[rootVal]+1, end);
        
        return root;
    }
};
// @lc code=end

