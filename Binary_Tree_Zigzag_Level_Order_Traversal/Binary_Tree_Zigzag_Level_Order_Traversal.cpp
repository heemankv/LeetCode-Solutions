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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        int flag = true;

        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> ans;
            int sez = q.size();

            for(int i = 0 ; i < sez; i++){
                // go get the top
                TreeNode* temp = q.front();
                // remove it 
                q.pop();

                // push it's children to q
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                if(flag){
                ans.push_back(temp->val);
                } else{
                    ans.insert(ans.begin(),temp->val);
                }
            }
            result.push_back(ans);
            flag = !flag;
        }
        return result;
    }
};
