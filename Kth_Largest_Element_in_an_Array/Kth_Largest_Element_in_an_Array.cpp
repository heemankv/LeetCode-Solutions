#include<bits/stdc++.h>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        // need to iterate on all the arrays 
        // but need only to store n elements

        priority_queue<int,vector<int>, greater<int>> KTopElements;
        for(int i = 0 ; i < n; i++){

            if(KTopElements.size() < k){
                KTopElements.push(nums[i]);
                continue;
            }
            if(KTopElements.top() < nums[i]){
                KTopElements.pop();
                KTopElements.push(nums[i]);
            }
        } 
        return KTopElements.top();
    }
};
