class Solution {
public:
    void merge(vector<int>& nums1, const int size1, const vector<int>& nums2, const  int size2) {
        int p1 = size1-1;
        int p2 = size2-1;
        int pk = size1 + size2 - 1;

        while(p1 >=0 && p2 >=0){
            // if p1 is the number to put
            if(nums1[p1] > nums2[p2]){
                nums1[pk] = nums1[p1];
                p1--;
                pk--;
            }
            else{
                nums1[pk] = nums2[p2];
                p2--;
                pk--;
            }
        }
        // now it is to note that, nums1 will already be sorted if p1 is left
        // so no need for any loop on that

        while(p2>=0){
            nums1[pk] = nums2[p2];
                p2--;
                pk--;
        }
    }




    //  void merge(vector<int>& nums1, const int size1, const vector<int>& nums2, const  int size2) {
    //     vector<int> newNums1(size1,0);
    //     for(int i = 0 ; i < size1; i++){
    //         newNums1[i] = nums1[i];
    //     }
    //     nums1 = {};
    //     int p1 = 0;
    //     int p2 = 0;

    //     while(p1 < size1 && p2 < size2){

    //         if(newNums1[p1] < nums2[p2]){
    //             nums1.push_back(newNums1[p1]);
    //             p1++;
    //         }
    //         else if(newNums1[p1] == nums2[p2]){
    //             nums1.push_back(newNums1[p1]);
    //             p1++;
    //         }
    //         else if(newNums1[p1] > nums2[p2]){
    //             nums1.push_back(nums2[p2]);
    //             p2++;
    //         }
    //     }
        
    //     while(p1<size1){
    //         nums1.push_back(newNums1[p1]);
    //         p1++;
    //     }
    //     while(p2<size2){
    //         nums1.push_back(nums2[p2]);
    //         p2++;
    //     }

    // }
};
