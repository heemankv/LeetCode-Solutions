class Solution {
public:
    void answer(const int N, const int currentN, int K, vector<vector<int>>& mainAnswer, vector<int>& currAnswer) {
        // If current k == 0, push to answer
        if (currAnswer.size() == K) {
            mainAnswer.push_back(currAnswer);
            return;
        }

        // Recursive looping with backtracking
        for (int i = currentN; i <= N; i++) {
            // Pick
            currAnswer.push_back(i);
            answer(N, i + 1, K, mainAnswer, currAnswer);
            // Don't pick
            currAnswer.pop_back();
            // answer(N, i + 1, K, mainAnswer, currAnswer);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> mainAnswer;
        vector<int> subanswer;
        answer(n, 1, k, mainAnswer, subanswer);
        return mainAnswer;
    }
};

