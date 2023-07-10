class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;

        int interval = 0;
        vector<int> currInterval = intervals[0];
        while(interval < n){
            vector<int> nextInterval = intervals[interval];
            if(currInterval[1] >= nextInterval[0]){
                // merge
                vector<int> qwer = {currInterval[0], max(currInterval[1],nextInterval[1])};
                currInterval = qwer;
            }
            else if(nextInterval[1] > currInterval[0]){
                merged.push_back(currInterval);
                currInterval =  nextInterval;
            }
            interval++;
        }
        merged.push_back(currInterval);
        return merged;
    }
};
