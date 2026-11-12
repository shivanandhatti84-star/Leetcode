class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int r=0;
        unordered_map<int,int> mapl;
        int ms=0;
        for(int i=0;i<fruits.size();i++){
            mapl[fruits[i]]++;
            while(mapl.size()>2){
                mapl[fruits[r]]--;
                if(mapl[fruits[r]]==0) mapl.erase(fruits[r]);
                r++;
            }
            ms=max(ms,i-r+1);
        }
        return ms;
    }
};