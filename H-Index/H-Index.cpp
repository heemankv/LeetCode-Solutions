class Solution {
public:


    bool check(vector<int>& citations, int possibleAnswer){
        int ans = 0;
        for(auto cit : citations){
            if(cit >= possibleAnswer ){
                ans++;
            }
        }
        return ans >= possibleAnswer;
    }




    int hIndex(vector<int>& citations) {
        int maxCit = 0;
        for(int cit:citations){
            maxCit = max(maxCit,cit);
        }

        if(citations.size() == 0 ){return -1;} 



        int answer = -1;
        // binary search
        int low = 0;
        int high = maxCit;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(check(citations,mid)){
                answer = max(mid,answer);
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
       }
       return answer;
    }
};
