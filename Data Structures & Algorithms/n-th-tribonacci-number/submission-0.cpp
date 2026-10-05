class Solution {
public:
    int tribonacci(int n) {
        if(n==0)    return 0;
        if(n==1 || n==2)    return 1;
        int x1, x2, x3;
        x1 = 0;
        x2 = 1;
        x3 = 1;
        int ans = 1;
        n-=2;
        while(n--){
            ans = x1+x2+x3;
            x1= x2;
            x2 = x3;
            x3 = ans;
        }
        return ans;
    }
};