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
    int finalAnswer = 0;
private:
    void helper(TreeNode* node, int parentAnswer,int &finalAnswer){
        // base case NULL
        if(node == NULL){
            return;
        }

        // add me to parent's answer
        int currentAnswer = parentAnswer;

        currentAnswer *= 10;
        currentAnswer += node->val;

        // if I am a leaf, add my answer to final answer 
        if(node->left == NULL &&  node->right == NULL){
            finalAnswer += currentAnswer;
        }
        // you are not a leaf so call on your children to get answer using your answer;
        else{
            helper(node->left, currentAnswer, finalAnswer);
            helper(node->right, currentAnswer, finalAnswer);
        }
    }


public:
    int sumNumbers(TreeNode* root) {
        int finalAnswer = 0;
        int currentAnswer = 0;
        helper(root,currentAnswer,finalAnswer);
        return finalAnswer;
    }
};
