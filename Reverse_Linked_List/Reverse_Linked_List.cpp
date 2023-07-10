/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

private:
    ListNode * reverseLoop(ListNode* head){
        if(head == NULL) return NULL;
        ListNode *  curr = head;
        ListNode * prev = NULL;
        ListNode * fwd = NULL;
        
        while(curr != NULL){
            // prepare
            fwd = curr->next;
            // reverse
            curr->next = prev;
            // next
            prev = curr;
            curr = fwd;
        }
        return prev;
    }


private:
    ListNode * reverseRecursive(ListNode* head){
        // base case
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* sorted = reverseRecursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return sorted;
    }

private:
    ListNode* reverseList( ListNode* start, ListNode* end, ListNode* nextEnd) {
        stack<ListNode*> nodes;
        ListNode* head = start;
        while(head != nextEnd){
            nodes.push(head);
            head = head->next;
        }
        
        head = new ListNode();
        ListNode*  res = head;
        while(!nodes.empty()){
            head->next = nodes.top();
            nodes.pop();
            head = head->next;
        }
        head->next = nextEnd;
      
        return res->next;
    }




public:

    ListNode* reverseList(ListNode* head) {
        ListNode* end = NULL;
        ListNode* temp = head;

        // while(temp!= NULL && temp->next != NULL){
        //     temp = temp->next;
        // }
        // return reverseList( head,temp,NULL);
        // return reverseRecursive(head);
        return reverseLoop(head);
        
    }

};
