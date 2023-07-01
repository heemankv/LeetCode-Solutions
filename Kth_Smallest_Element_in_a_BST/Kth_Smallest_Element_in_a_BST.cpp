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
// we can return -1 as a faulty output, since the code always expects +ve values
private:
    int inOrder(TreeNode* root, vector<int> &vec, int k){
        if(root == NULL){
            return -1;
        }
       
        // Left call
        int leftResult = inOrder(root->left, vec, k);
        if (leftResult != -1) {
            return leftResult;
        }

        // push N
        vec.push_back(root->val);
        if (vec.size() == k) {
            return vec[k-1];
        }

        // Right call
        int rightResult = inOrder(root->right, vec, k);
        if (rightResult != -1) {
            return rightResult;
        }
        return -1;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> qwe;
        return inOrder(root,qwe,k);
    }
};
