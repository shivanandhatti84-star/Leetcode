class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xors=0;
        for(int i=0;i<nums.size();i++){
            xors^=(long long)nums[i];
        }
        long long c=(xors&(xors-1))^xors;
        long long xor1=0,xor2=0;
        for(int i=0;i<nums.size();i++){
            if(c&nums[i]){
                xor1^=(long long)nums[i];
            }
            else{
                xor2^=(long long)nums[i];
            }
        }
        if(xor1>xor2){
            return {(int)xor1,(int)xor2};
        }
        return {(int)xor1,(int)xor2};
    }
};