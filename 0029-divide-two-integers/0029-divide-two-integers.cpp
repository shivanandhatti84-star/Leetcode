class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(divisor==1) return dividend;
        if(divisor==-1) return -dividend;
        bool pos=true;
        if(dividend>=0 && divisor<0) pos=false;
        if(dividend<0 && divisor>0) pos=false;

        long long n=dividend;
        long long m=divisor;
        n=abs(n);
        m=abs(m);
        long long p=m;
        long long ans=0,sum=0,count=1;
        while((sum+m)<=n){
            ans+=count;
            sum+=m;
            m+=m;
            count+=count;
        }
        m=p;
        while(sum+m<=n){
            ans++;
            sum+=m;
        }

        if(ans>INT_MAX && pos) return INT_MAX;
        if(ans>INT_MAX && !pos) return INT_MIN;

        return pos?ans:-ans;

    }
};