class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> prefix(n);
        vector<int>suffix(n);
        
          prefix[0] = 1;
        suffix[n-1] = 1;

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for (int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};




//   int n = nums.size();
//     vector<int> p(nums), s(nums);
    
//     for (int i = 1; i < n-1; i++)  //storing prefix and suffix
//     {
//         p[i] *= p[i-1]; //start to end
//         s[n-i-1] *= s[n-i]; //end to start
//     }
//     ans[0] = s[1], ans[n-1] = p[n-2]; //first and last index doesn't have prefix and suffix respectively. 
    
//     for (int i = 1; i < n-1; i++)  ans[i] = p[i-1]*s[i+1];

//     return ans;
