class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        //First Occurence
        int start=0,end=nums.size()-1;
        int mid=(start+end)/2;
        while(start<=end){
            mid=(start+end)/2;
            if(target==nums[mid]){
                ans[0]=mid;
                end=mid-1;
            }
            else if(target<nums[mid]){
                end=mid-1;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
        }
        //last occurence
        start=0,end=nums.size()-1;
        while(start<=end){
            mid=(start+end)/2;
            if(target==nums[mid]){
                ans[1]=mid;
                start=mid+1;
            }
            else if(target<nums[mid]){
                end=mid-1;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
        }
        return ans;
    }
};
