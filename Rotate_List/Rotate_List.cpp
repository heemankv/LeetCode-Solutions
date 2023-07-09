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
    ListNode* rotateRight(ListNode* head, int k) {
        // TODO: empty base case
        if(head == NULL || head->next == NULL ){
            return head;
        }
        // count n
        ListNode* tail = head;
        int n = 1;
        while(tail != NULL && tail->next != NULL){
            tail = tail->next;
            n++;
        }
        int kth = k%n;

        if(kth == 0){
            return head;
        }
        // now we have last node and n

        ListNode* prev = head;
        for(int i = 0 ; i <n-kth-1 ;i++){
            prev = prev->next;
        }

        // prev
        // tail
        // head
        ListNode* newHead = prev->next;
        
        prev->next = NULL;
        tail->next = head;

        return newHead;

    }
};
