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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // / base case check   
        if(head == NULL){
            return NULL;
        }
        // prepare for while loop
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        // check k ki existance

        ListNode* temp = head;
        // if there are no. k elements then dont reverese
        for(int i = 0 ; i < k ; i++){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
        }

        // now that k elements exists
        int count = 0;

        // while k reverse
        while(curr!=NULL && count<k ){
            // prepare
            forward = curr->next;
            // reverse
            curr->next = prev;
            // next
            prev = curr;
            curr = forward;
            count++;
        }

        // forward == current == temp
        // call recursion on next and take the input to head->next since head is last now

        // forward will be the next element to the current rotated element
        if(forward != NULL){
            head->next = reverseKGroup(forward,k);
        }

        // now return prev as usual;
        return prev;
    
    }
};
