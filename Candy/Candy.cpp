class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1){
            return 1;
        }
        int n = ratings.size();
        int count = 0;
        vector<int> prefixAns(n,1);
        vector<int> suffixAns(n,1);

        for(int i = 1 ; i < n ; i++){
            if(ratings[i] > ratings[i-1]){
                prefixAns[i] += prefixAns[i-1];
            }
        }
        
        for(int i = n-2 ; i >=0 ; --i){
            if(ratings[i] > ratings[i+1]){
                suffixAns[i] += suffixAns[i+1];
            }
        }

        for(int i = 0 ; i < n ; i++){
            int elemAnswer = max(prefixAns[i], suffixAns[i]);
            cout<<elemAnswer<<endl;
            count +=elemAnswer;
        }
        return count;
    }
};
