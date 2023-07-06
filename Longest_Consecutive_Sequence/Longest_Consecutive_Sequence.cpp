class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        set<int>st;
        // push all to set
        // push all to hashset

        for(int num:arr){
            st.insert(num);
        }

        int longest = 0;
        // make a longest counter
        // loop on all the values of array
        // for each element if tjhe 
        // for all the elements 
        for(auto num:arr){
            // does previous exist
            // if no then make this first
            // if my prev is not in hashset then it means I am the first one in here, that means I am the origin
            // so start counting till you find my next
            if(!st.count(num-1)) {
                // starting elem
                int currentStreak = 1;
                int currentElem = num;

                while(st.count(currentElem+1)){
                    currentStreak+=1;
                    currentElem+=1;
                }
                
                longest = max(longest,currentStreak);
            }

        }
        return longest;
    }
};




