class Solution {
public:

    void helper(const vector<int>& candidates, const  int target, vector<vector<int>>& mainAnswer, vector<int> & currAnswer, int currSum, int currIndex) {
        // base case
        if(currSum > target) return;
        if(currSum == target){
            mainAnswer.push_back(currAnswer);
        }
        // recursive calls with small calculation
        for(int i = currIndex; i < candidates.size(); i++){
            // push me to answer
            currAnswer.push_back(candidates[i]);
            currSum += candidates[i];
            // call rec
            helper(candidates, target, mainAnswer, currAnswer, currSum, i);
            // pop me from asnwer
            currAnswer.pop_back();
            currSum -= candidates[i];
        }
        return;  
    }




    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> mainAnswer;
        vector<int> currAnswer;
        int currSum =0;
        int currIndex = 0;
        helper(candidates,target,mainAnswer, currAnswer, currSum, currIndex);
        return mainAnswer;
    }
};
