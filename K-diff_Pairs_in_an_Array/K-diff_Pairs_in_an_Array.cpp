class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(const int elem:nums){
            freq[elem]++;
        }
        int answer = 0;

        for(auto x:freq){
            if(k == 0){
                if(x.second >1){
                    answer++;
                }
            }
            else if(freq.find(x.first+k) !=freq.end()){
                answer++;
            }
        }
        return answer;
    }
};
