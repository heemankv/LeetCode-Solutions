class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        for(auto i:intervals){
            // three cases for sure
            // 1 :  i is stricktly smaller than newInterval
            if(i[1]< newInterval[0]){
                // push i
                answer.push_back(i);
            }
            // 2 :  i is stricktly greater than newInterval
            else if(i[0] > newInterval[1]){
                // push i
                answer.push_back(newInterval);
                newInterval=i;//updating the new interval

            }
            // 3 :  i is in range of newInterval
            else{
                newInterval[0]=min(newInterval[0],i[0]);
                newInterval[1]=max(newInterval[1],i[1]);
            }   
        }
        answer.push_back(newInterval);
        return answer;  
    }
};
