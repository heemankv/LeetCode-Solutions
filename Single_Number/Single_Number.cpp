class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int answer = nums[0];
        for(int i = 1; i < n; i++){
            answer ^= nums[i];
        }
        return answer;
    }
};
