class Solution {
public:
    void answer(string digits, vector<string>& ans, string val) {
        // base case
        if (digits.empty()) {
            ans.push_back(val);
            return;
        }

        // For all my possible combinations
       vector<vector<char>> digitVal = {
            {},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };


        int num = digits[0] - '0';
        digits = digits.substr(1);

        // num is the first digit of the string
        for (auto itr : digitVal[num]) {
            // add me to answer
            val.push_back(itr);
            // call recursion with my any value
            answer(digits, ans, val);
            // remove me from answer
            val.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {

        vector<string> create;
        if(digits.empty()) return create;
        string ans;
        answer(digits, create, ans);
        return create;
    }
};

