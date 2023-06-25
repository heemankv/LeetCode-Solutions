class Solution {
public:
    int lengthOfLastWord(string s) {
        int siz=s.size(),kount=0,flag=0;
        for(int i=siz-1;i>=0;i--){
            if(s[i]==' ' && kount!=0)break;
            if(s[i]!=' '){
                kount++;
            }
        }
        return kount;
    }
};
