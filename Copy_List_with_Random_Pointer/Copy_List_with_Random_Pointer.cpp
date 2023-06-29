/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node* > mpp;

        Node* ll = head;
        while(ll != nullptr){
            Node*  newNode = new Node(ll->val);
            mpp[ll]= newNode;
            ll = ll->next;
        }
        for(auto it:mpp){
            if(it.first->next != nullptr){
                mpp[it.first]->next = mpp[it.first->next];
            }
            if(it.first->random != nullptr){
                mpp[it.first]->random = mpp[it.first->random];
            }
        }
        return mpp[head];


        
    }
};
