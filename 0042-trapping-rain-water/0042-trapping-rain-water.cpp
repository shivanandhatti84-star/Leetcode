class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxl=0,maxr=0,total=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxl){
                    maxl=height[left];
                }
                else{
                    total+=maxl-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=maxr){
                    maxr=height[right];
                }
                else{
                    total+=maxr-height[right];
                }
                right--;
            }
        }
        return total;
    }
};