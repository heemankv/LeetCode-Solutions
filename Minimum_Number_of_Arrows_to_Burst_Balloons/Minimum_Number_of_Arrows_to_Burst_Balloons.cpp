bool cmp(vector<int>&a, vector<int>&b){
    if(a[1] == b[1])return a[0] <= b[0];
    return a[1] <= b[1];
}
class Solution {

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), cmp);
        int answer = 0;
        int index = 0;
        while(index<n){
            int leftt = points[index][1];
            // abb iss vale ko phodne ke liye mujhe dart toh chahiye hi
            answer++;
            // now compare the current end to the next elems
            index++;
    
            while(index<n && points[index][0] <= leftt ){
                index++;
            }

            // compare end with all start

        }
        return answer;
    }
};

// public:
//        int findMinArrowShots(vector<vector<int>>& points) {
//         sort(points.begin(), points.end(), cmp);
//         int ans = 0;
//         int n = points.size();
//         int ind = 0;
//         while(ind < n){
//             int left = points[ind][1];
//             ans++;
//             ind++;
//             while(ind < n and points[ind][0] <= left)ind++;
//         }
//         return ans;
//     }
// };
