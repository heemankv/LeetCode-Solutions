class Solution {
public:

    //  Sliding Window Approach!
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lastSeenAt;
        int n = s.length();
        int l = 0;
        int r = 0;
        int length = INT_MIN;

        while(r < n){

            // if valid
            if(lastSeenAt.find(s[r]) != lastSeenAt.end()){
                //  update l
                l = max(l,lastSeenAt[s[r]]+1);
            }
            // max/ min update
            length = max(length , r - l + 1);
            // normal task
            lastSeenAt[s[r]] = r;
            // counter update
            r++;

        }

        return length == INT_MIN ? 0 :  length;


    }
};




// #include <bits/stdc++.h> 
// int uniqueSubstrings(string s)
// {
//     // last seen on!
//     unordered_map<char,int> mp;
//     int left = 0;
//     int right = 0;
//     int len= 0;
//     int n = s.length();
//     while(right < n) {
//         // update count on found
//         if(mp.find(s[right]) != mp.end()){
//             left = max(left, mp[s[right]]+1);
//         }
//         // update value in map
//         mp[s[right]] = right;

//         // update length on every loop 
//         len = max(right - left + 1, len);

//         right++;

//     }
//     return len;


//     //Write your code here
// }
