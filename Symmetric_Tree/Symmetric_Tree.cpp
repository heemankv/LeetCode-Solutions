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

private:
    bool areSame(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL && root2 != NULL){
            return false;
        }
        if(root2 == NULL && root1 != NULL){
            return false;
        }

        if(root1->val == root2->val){
            return areSame(root1->left, root2->right) && areSame(root1->right, root2->left);
        }
        return false;
    }



public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return areSame(root->left, root->right);
    }
};
