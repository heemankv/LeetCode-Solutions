/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* ith = head;
        ListNode* jth = head;
        do{

            if(ith && ith->next){
                ith = ith->next;
            }
            else{
                return false;
            }
            if(jth &&  jth->next&& jth->next->next){
                jth = jth->next->next;
            }
            else{
                return false;
            }
        }
        while(ith != jth);
        return true;
        
    }
};
