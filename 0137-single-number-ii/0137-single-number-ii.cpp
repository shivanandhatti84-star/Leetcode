// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int result=0;       
//         for(int i=0;i<32;i++){
//             int sum=0;
//             for(int num:nums){
//                 if(num>>i&1==1){
//                     sum++;
//                 }
//             }
//             if(sum%3!=0){
//                 result=result|(1<<i);
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int lanMot = 0;
        int lanHai = 0;

        for (int giaTri : nums) {
            lanMot = (lanMot ^ giaTri) & ~lanHai;
            lanHai = (lanHai ^ giaTri) & ~lanMot;
        }

        return lanMot;
    }
};