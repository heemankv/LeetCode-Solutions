class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        // not sure
        if( x == INT_MIN) return;

        long long ans = 0;
        bool flagOfNegativity = false;
        if(x < 0){
            flagOfNegativity = true;
        }
        x  = abs(x);

        while(x != 0){
            if(ans*10 > INT_MAX || ans*10 < INT_MIN){
                return 0;
            }
            ans = ans*10 + x%10;
            x = x/10;
        }

        return  flagOfNegativity ? 0-ans : ans;

    }
};
