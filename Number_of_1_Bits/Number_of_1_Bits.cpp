class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0;

        for(int i = 0 ;  i< 32; i++){

            int a = n&1;
            if(a){
                answer++;
            }
            n = n >>1;
        }
        return answer;
    }
};
