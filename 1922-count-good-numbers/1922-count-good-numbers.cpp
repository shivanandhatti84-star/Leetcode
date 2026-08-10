class Solution {
public:
    long long MOD = 1000000007;

    long long mypow(long long n,long long x){
        if(x==0) return 1;
        if(x%2==0) return mypow(n*n % MOD,x/2);
        return n*mypow(n,x-1)%MOD;
    }
    int countGoodNumbers(long long n) {
        long long x=n/2;
        long long y=n-n/2;
        long long n1=mypow((long long)4,x)%MOD;
        long long n2=mypow((long long)5,y)%MOD;
        return (n1*n2)%MOD;
    }
};