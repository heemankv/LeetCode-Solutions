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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }

        // now make my prev
        ListNode* prev = new ListNode();
        ListNode* prev2 = prev;
        prev->next = head;



        while(prev ->next != NULL && prev->next->next != NULL){
            if(prev->next->val == prev->next->next->val){
                int var = prev->next->val;
                while(prev -> next != NULL && prev->next->val == var){
                    prev->next = prev->next->next;
                }
            }
            else{
                prev = prev->next;
            }
        }
        return prev2->next; 
    }
};
