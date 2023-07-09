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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL){ // head might be defined for head->next != NULL, so we need to ensure that we return head
            return head;
        }

        // go to prev of left and store it
        ListNode* prevLeft = new ListNode();
        ListNode* prevLeftInit = prevLeft;
        prevLeft->next = head;
        
        while(prevLeft->next != NULL && prevLeft->next->val != left ){
            prevLeft = prevLeft->next;
        }

        // I would need a copy of my prev

        ListNode* prev = prevLeft;
        ListNode* fwd = NULL;
        ListNode* current = prevLeft->next; // i am sure this won't be null because of above for loop.
        ListNode* leftPtr = prevLeft->next;

        // do a while loop reversal with copies of all the objects
        while(current!=NULL && prev->val != right){
            // store
            fwd = current->next;
            // swap
            current->next = prev;
            // next
            prev = current;
            current = fwd;
           
        }

        // merge last points
        // the values of the left to right guys are reveresed
        // merge faily hui values
        prevLeft->next = prev;
        leftPtr->next = fwd;
        return prevLeftInit->next;
    }
};


