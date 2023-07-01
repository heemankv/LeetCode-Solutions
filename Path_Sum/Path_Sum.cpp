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
    bool isIT(TreeNode* root, int targetSum, int currSum){
        if(root == NULL){
           return false;
        }
        currSum = currSum + root -> val;
        if(root -> left == NULL && root -> right == NULL){
            if(currSum == targetSum){
                return true;
            }
            else{
                return false;
            }
        }

        bool answer = false;
        if(root->left){
            answer = answer || isIT(root->left, targetSum , currSum);
        }
        if(root->right){
            answer =  answer || isIT(root->right, targetSum , currSum);
        }
        return answer;

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        // handle null root case
        return isIT(root, targetSum, 0);
    }
};
