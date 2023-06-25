class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majorIndex = 0;
        int count = 1;
        int index = 1;
        while(index<n){
            if(nums[index] == nums[majorIndex]){
                count++;
            }
            else{
                count--;
            }

            if(count==0){
                count = 1;
                majorIndex = index;
            }
            index++;
        }
        return nums[majorIndex];
    }
};
// more's voting algo, halka kar sakta tha main isko
