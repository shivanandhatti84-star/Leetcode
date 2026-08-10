class Solution {
public:
    double mypow(double x,long long n){
        if(n==1) return x;
        if(n%2==0) return (mypow(x*x,n/2));

        return x*mypow(x,n-1);
    }
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(n==0) return 1;
        if(n==1) return x;
        long long num=n;
        if (num < 0) {
            // Calculate the power of -n and take reciprocal
            return (1.0 / mypow(x, -1*num));
        }
        return mypow(x,num);
    }
};