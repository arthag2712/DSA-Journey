class Solution {
public:
    long long sumArr(vector<int> &piles, int mid){
        long long sum=0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            if(piles[i]%mid != 0){
                sum += (piles[i]/mid)+1;
            }else{
                sum += (piles[i]/mid);
            }
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,(long long)piles[i]);
        }
        long long low = 1, high = ans;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long check = sumArr(piles, mid);
            if(check <= h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};