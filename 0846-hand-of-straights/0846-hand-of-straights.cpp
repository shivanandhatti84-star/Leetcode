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
        auto it=mapl.begin();
        while(it!=mapl.end()){

            int co=it->second;
            if(co==0){
                ++it;
                continue;
            }
            int start=it->first;
            for(int i=0;i<groupSize;i++){
                if(mapl[start+i]<co) return false;
                mapl[start+i]-=co;
            }
            ++it;
        }
        return true;
    }
};