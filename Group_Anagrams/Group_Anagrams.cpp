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



    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> mp;
        for(auto strr:strs){
            string s = strr;
            sort(s.begin(),s.end());
            mp[s].push_back(strr);
        }
        vector<vector<string>> ans;
        for(auto mpp:mp){
            ans.push_back(mpp.second);   
        }
        return ans;
    }
};
