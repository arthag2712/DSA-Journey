class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int tot=0,l=0,r=n-1,lMax=0,rMax=0;
        while(l<r){
            lMax = max(height[l],lMax);
            rMax = max(height[r],rMax);
            if(lMax<=rMax){
                tot+= (lMax-height[l]);
                l++;
            }else if(rMax < lMax){
                tot+= (rMax-height[r]);
                r--;
            }
        }
        return tot;
    }
};