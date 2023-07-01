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
    void rec(vector<int> &answer, TreeNode* node, int level){
        if( node == NULL){
            return;
        }

        // push to print
        if(level == answer.size()){
            answer.push_back(node->val);
        }
        // NRL
        // call right 
        rec(answer,node->right,level+1);
        rec(answer,node->left,level+1);
        return;
    }


    vector<int> rightSideView(TreeNode* root) {
        // aage mat badhna if root is empty
        int level = 0;
        vector<int> ans;
        rec(ans,root,level);
        return ans;



        // vector<int> ans;
        // if(root == NULL){
        //     return ans;
        // }
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int sez = q.size();
        //     for(int i = 0 ; i < sez; i++){
        //         // go get the top
        //         TreeNode* temp = q.front();
        //         // remove it 
        //         q.pop();

        //         // push it's children to q
        //         if(temp->left){
        //             q.push(temp->left);
        //         }
        //         if(temp->right){
        //             q.push(temp->right);
        //         }

        //         // if i is sez-1 then push to answer
        //         if(i == sez-1){
        //             ans.push_back(temp->val);
        //         }
        //     }

        // }
        // return ans;
    }
};
