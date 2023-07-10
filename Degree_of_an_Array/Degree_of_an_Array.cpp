class Solution {

// Brute force solution is 3hashmaps to maintain count, first index, last index

public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq, start;
        int minLength = INT_MAX;
        int maxDegree = INT_MIN;
        
        for(int i = 0 ; i < n ; i++){
            // update freq
            freq[nums[i]]++;
            // update first index
            if(start.find(nums[i]) == start.end()){
                start[nums[i]] = i; 
            }
            // this number has degree greater than mine, update it
            if(freq[nums[i]] > maxDegree){
                maxDegree = freq[nums[i]];
                minLength = i - start[nums[i]] + 1;
            }else if(freq[nums[i]] == maxDegree){
                // a degree >= current is already there, so see if you have 
                minLength = min(minLength, i - start[nums[i]] + 1);
            }
        }
        return minLength == INT_MAX ? n : minLength ;

        
    }
};
