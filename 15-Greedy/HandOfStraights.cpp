class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;
        map<int,int> mpp;
        for(int card : hand){
            mpp[card]++;
        }
        while(!mpp.empty()){
            int start = mpp.begin()->first;
            for(int i = start; i<start+groupSize;i++){
                if(!mpp[i]) return false;
                mpp[i]--;
                if(mpp[i]==0) mpp.erase(i);
            }
        }
        return true;
    }
};
