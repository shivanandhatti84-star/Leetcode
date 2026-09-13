class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        map<int,int> mapl;
        for(int i=0;i<hand.size();i++){
            mapl[hand[i]]++;
        }
        
        while(!mapl.empty()){
         auto it=mapl.begin();
            int co=it->second;
            if(co==0){
                ++it;
                continue;
            }
            int start=it->first;
            for(int i=0;i<groupSize;i++){
                if(mapl[start+i]<co) return false;
                mapl[start+i]-=co;
                if(mapl[start+i]==0)mapl.erase(start+i);

            }
            ++it;
        }
        return true;
    }
};