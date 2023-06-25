class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        istringstream in(s); string word;
        int i = 0, n = pattern.size();
        for(word; in>>word; i++){
            if(p2s.find(pattern[i]) != p2s.end() &&  p2s[pattern[i]] != word) return false;
            if(s2p.find(word) != s2p.end() &&  s2p[word] != pattern[i]) return false;
            p2s[pattern[i]] = word;
            s2p[word] = pattern[i];
        }
        return i==n; 
    }
};
