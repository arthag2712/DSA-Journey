class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n){
            ans++;
            n = n & (n-1); //unsets last set bit, so loop only runs till no. of ones
        }
        return ans;
    }
};
