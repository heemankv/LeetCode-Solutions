class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        // n > 1 cases
        //get it's previous value
        // count and say previous value 
        // n = 2 ÷ will count and say using answer from 1

        string prevAnswer = countAndSay(n-1);

        string myAnswer = "";

        int start = 0;
        int end = prevAnswer.length();

        while(start < end){
            // got an element 
            // check it's similar count ahead
            int nextIndex = start;
            while(nextIndex < end &&  prevAnswer[nextIndex] == prevAnswer[start]){
                nextIndex++;
            }

            int startCount = nextIndex - start;
            string ans = to_string(startCount) + prevAnswer[start];
            myAnswer += ans;
            start = nextIndex;
        }
        return  myAnswer;
    }
};
