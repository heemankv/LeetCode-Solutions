/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

private:
    Node* dfs(Node* node, unordered_map<Node*,Node*> &mp){
        // kya hoga yahan pr ?
        // make a clone 
        Node* clone = new Node(node->val);
        // make a temp array like neighbours
        vector<Node*> temp;
        // push original and clone to map
        mp[node] = clone;

        // check on each element of neighbours
        for(auto itr:node->neighbors){
            // if already in map add and go
            if(mp.find(itr) != mp.end()){
                // push
                temp.push_back(mp[itr]);
            }else{
                // if not in map then call dfs create and go
                Node* dfsReturn = dfs(itr,mp);
                temp.push_back(dfsReturn);
            }
        }
        clone->neighbors = temp;
        return clone;
    }



public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        //  base case handling 
        if(node == NULL){
            return NULL;
        }
        if(node->neighbors.size() == 0){
            // one 1 elem
            return new Node(node->val);
        }
        // else any case call dfs and return 
        return dfs(node, mp); 
    }
};
