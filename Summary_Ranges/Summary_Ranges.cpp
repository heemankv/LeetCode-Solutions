#include <bits/stdc++.h>

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> answer;

        int start = 0;
        string range ="";

        while(start < n){

            int oldStart = start;

            while(start+1 < n && nums[start+1] == nums[start]+1){
                start++;
            }

            string s = "";
            if(oldStart != start){
                s = to_string(nums[oldStart]) + "->" + to_string(nums[start]);
            } else{
                s = to_string(nums[oldStart]);
            }

            answer.push_back(s);
            start = start+1;
        }
        return answer; 
    }
};
