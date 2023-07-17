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



#include <bits/stdc++.h>


class myComparator
{
public:
    int operator() ( ListNode* a,  ListNode* b)
    {
        return a->val >= b->val;
    }
};
  
class Solution {



public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* answer = new ListNode();
        ListNode* answer1 = answer;

        // defined order
        priority_queue<ListNode*,vector<ListNode*>, myComparator> miniOrder;

        // pushed all
        for(const auto linked:lists){
            if(linked != NULL){
                miniOrder.push(linked);
            }
        }

        //while 
        while(!miniOrder.empty()){
            // get the mini Node of them all
            ListNode* elem = miniOrder.top();
            miniOrder.pop();
            if(elem->next != NULL){
                miniOrder.push(elem->next);
            }
            answer->next = elem;
            answer = answer->next;
        }
        return answer1->next;
    }
};
