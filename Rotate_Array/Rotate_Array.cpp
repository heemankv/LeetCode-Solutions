#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {


        // check edge case
        k = k %nums.size();
        int pt = nums.size() - 1 - k;

        if (nums.size() == 0 || nums.size() == 1) {
          return;
        }


        // rotate whole arr
        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse( nums.begin() + k, nums.end());




    }
};
