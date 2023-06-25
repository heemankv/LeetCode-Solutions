#include <string>
class Solution {
public:


    // compare and return lenght of max common of two strings

    int commonFind(string a, string b){
        int count = 0;
        int i = 0;
        int len1 = a.length();
        int len2 = b.length();
        for(int i = 0 ; i < min(len1,len2);i++){
            if(a[i] != b[i]){
                break;
            }
            count++;
        }
        return count;
    }

    string longestCommonPrefix(vector<string>& strs) {
        // for all the strings in the vector call common find
        // if result is lesser than mini, uopdate mini
        
        int mini = INT_MAX;
        for(int i = 0 ; i < strs.size()-1;i++){
            int answer = commonFind(strs[i], strs[i+1]);
            mini = min(mini,answer);
        }
        if(mini == 0){
            return "";
        }else{
            return strs[0].substr(0,mini);
        }

    }
};
