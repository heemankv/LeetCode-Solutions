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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        }
        else if(list2 == nullptr){
            return list1;
        }
        //  make pointers
        ListNode * l1 = list1;
        ListNode * l2 = list2;

        if(l1->val > l2->val){
            return mergeTwoLists(l2,l1);
        }
        ListNode *res = list1;
        while(l1!=nullptr && l2!=nullptr){
            // chalate raho

            // need temp var
            ListNode* temp = nullptr;
            // compare l1
            while(l1 != nullptr && l2 != nullptr && l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }

            //  abb l1 bada hai l2 se
            temp->next = l2;
            std::swap(l1,l2);
        }
        return res;
    }
};
