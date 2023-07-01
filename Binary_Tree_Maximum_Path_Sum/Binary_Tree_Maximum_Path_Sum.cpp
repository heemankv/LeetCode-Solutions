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
    int solve(TreeNode* root, int &maxi){
        if(root == NULL){
            return 0;
        }
        //  dont consider <0 answers
        // call left
        int left = max(0,solve(root->left,maxi));
        // call right
        int right = max(0,solve(root->right,maxi));

        // let me add your answer to maxi
        maxi = max(maxi, left+right + root->val);

        // let me return my max len
        return max(left,right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maxi=INT_MIN;
        int result=solve(root,maxi);
        return max(maxi,result);
    }
};
