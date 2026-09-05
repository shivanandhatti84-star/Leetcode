class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int l=a.size()-1,r=0,sum=0,ms=0;

        while(r<k){
            sum+=a[r];
            r++;
        }
        if(k==l+1){
            return sum;
        }
        ms=max(sum,ms);
        r--;
        for(l=a.size()-1;l>=a.size()-k;l--){
            sum-=a[r--];
            sum+=a[l];
            ms=max(sum,ms);
        }
        return ms;
    }
};