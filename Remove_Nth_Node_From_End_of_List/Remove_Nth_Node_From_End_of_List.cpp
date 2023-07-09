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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( head == NULL || head->next == NULL ) return nullptr;

        ListNode* slow = new ListNode();
        slow->next = head;
        ListNode* res = slow;

        ListNode* fast = head;

        // iterate fast to the required index
        // n will never be invalid
        for(int i = 0; i < n-1; i++){
            fast = fast->next;
        }

        while(fast!=NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        // shift
        ListNode* temp = slow->next;

        slow->next = slow->next->next;

        // delete temp;

        return res->next;
 
    }
};
