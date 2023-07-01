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
    ListNode* partition(ListNode* head, int x) {
        //  making two ll
        ListNode* itr = head;

        ListNode* left = new ListNode();
        ListNode* right = new ListNode();
        ListNode* dummy1 = left;
        ListNode* dummy2 = right;

        // let's iterate

        while(itr != NULL){
            if(itr->val >= x){
                dummy2->next = itr;
                dummy2 = dummy2->next;
            }else {
                dummy1->next = itr;
                dummy1 = dummy1->next;
            }
            itr = itr->next;
        }
        dummy1->next = right->next;
        dummy2->next = NULL;
        return left->next;

    }
};
