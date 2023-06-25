class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;
        int index = 0;
        while(index < n){
            if(index == n-count-1 && nums[index] == val){
                count++; 
                break;
            }
            if(nums[index] == val){
                int pte = index;
                count++;
                while(pte < n -1){
                    nums[pte] = nums[pte +1];
                    pte++;
                }
            }
            else{
                index++;
            }
        }
    return n - count;
    }
};
