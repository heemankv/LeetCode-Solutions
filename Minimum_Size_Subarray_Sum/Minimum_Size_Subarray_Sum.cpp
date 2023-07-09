class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int wS = 0;
        int wE = 0;

        int mainAnswer = 1e9;
        int innerAnswer = 0;

        for(int wE = 0 ; wE < n ; wE++){
            // add each time, since remove will handle the excess cases
            innerAnswer += nums[wE];
            while(innerAnswer >= target){
                mainAnswer = min(mainAnswer, wE-wS+1);
                innerAnswer -= nums[wS];
                wS++;
            }
        }
        return mainAnswer == 1e9 ? 0 : mainAnswer;
    }
};
