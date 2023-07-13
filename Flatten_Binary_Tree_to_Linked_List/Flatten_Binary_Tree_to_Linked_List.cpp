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
    void flattern(TreeNode* root, TreeNode* &lastFixed_Right) {

        if(root == NULL) {return;}

        // Now
        // Right sort kro
        // Left sort kro
        // then mujhe sort kro

        flattern(root->right, lastFixed_Right);
        flattern(root->left, lastFixed_Right);

        // Now do me
        root->right = lastFixed_Right;
        root->left = NULL;
        // me is prev now
        // prev is last sorted
        lastFixed_Right = root;
        return;

    }

    void flatten(TreeNode* root) {
        TreeNode* lastFixed_Right = NULL;
        flattern(root, lastFixed_Right);
        return;
    }








    // void traverse2(vector<int>& v, TreeNode* root){
    //     if(root == NULL){
    //         return;
    //     }
    //     v.push_back(root->val); 
    //     traverse(v,root->left); 
    //     traverse(v,root->right); 
    // }

    // void flatten(TreeNode* root) {
    //     vector<int> v; 
    //     traverse(v, root); 

    //     //  i have order in v

    //     for(int it = 0 ; it < v.size(); it++){
    //         root->val = v[it];
    //         root->left = NULL;
    //         if(root->right == NULL && it !=v.size() -1){
    //             root->right = new TreeNode();
    //         }
    //         root = root->right;
    //     }
    // }
};
