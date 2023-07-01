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
    bool check(TreeNode* root , long mini, long maxi){
        if(root == NULL){
            return true;
        }

        if( (root->val > mini) && (root->val < maxi) ){
            //  check my left and right
            return (check(root->left, mini , root->val) && 
                check(root->right, root->val , maxi ));
        }
        return false;
    }


public:
    bool isValidBST(TreeNode* root) {
        // INT Min and Max is not enough
        return check(root, LONG_MIN, LONG_MAX);
    }
};
