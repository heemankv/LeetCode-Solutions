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
    void inOrder(TreeNode* root, vector<int> &vec){
        if(root == NULL){
            return;
        }
        // Inorder
        // L -> N -> R
        // Left call
        inOrder(root->left,vec);
        // push N
        vec.push_back(root->val);
        // Right call
        inOrder(root->right,vec);
        return;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> inorder;
        inOrder(root,inorder);

        // get min in sorted array
        int n = inorder.size();
        int mini = 1e9;
        
        // since sorted vec, no need for multi comparison, thus O(n)
        for(int i = 0 ; i <n-1 ; i++){
            int internal = abs(inorder[i+1] - inorder[i]);
            mini = min(internal,mini);
        }
        return mini;
    }
};

