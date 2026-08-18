class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long c=start^goal,count=0;
        while(c>0){
            if((c&1)==1) count++;
            c>>=1;
        }
        return count;
    }
};