class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int> countS;
        unordered_map<char,int> countT;
        for(auto elemS:s){
            countS[elemS]++;
        }
        for(auto elemT:t){
            countT[elemT]++;
        }

        for(auto elemX:s){
            if (countS[elemX] != countT[elemX]){
                return false;
            }
        }    
        return true;
    }
    
};
