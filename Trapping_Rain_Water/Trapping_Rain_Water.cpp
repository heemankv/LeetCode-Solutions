class Solution {
public:
    vector<int> getLmax(vector<int>& height, int n){
        vector<int> answer(n,1e9);
        answer[0] = height[0];
        for(int i = 1; i < n ; i++){
            answer[i] = max(answer[i-1], height[i]);
        }
        return answer;
    }

    vector<int> getRmax(vector<int>& height, int n){
        vector<int> answer(n,1e9);
        answer[n-1] = height[n-1];
        for(int i  = n-2; i >=0; i--){
            answer[i] = max(answer[i+1], height[i]);
        }
        return answer;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> Lmax = getLmax(height,n);
        vector<int> Rmax = getRmax(height,n);

        int answer = 0;
        for(int i =0 ; i <n ;i++){
            answer+= (min(Lmax[i],Rmax[i]) - height[i]);
        }

        return answer; 
    }
};
