class Solution {
public:
    int f(vector<int>& bloomDay, long long mid,int k){
        int nBoq = 0;
        int b=0;
        bool cons = true;
        int n=bloomDay.size();
        //O(nk) which was not feasible (TLE)
        // for(int i=0;i<n-k+1;i++){
        //     int j=0;
        //     for(j=0;j<k;j++){
        //         if(mid < bloomDay[i+j])
        //             break;
        //     }
        //     if(j==k){
        //         nBoq++;
        //         i+=k-1;
        //     }
        // }
        for(int i=0;i<n;i++){
            if(b==k){
                nBoq++;
                cons = false;
                b=0;
            }
            if(mid >= bloomDay[i]){
                b++;
                cons = true;
            }else{
                b=0;
                cons = false;
            }
        }
        if(b==k){
            nBoq++;
        }
        return nBoq;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL*m*k>n) return -1;
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, (long long)bloomDay[i]);
        }
        long long low =0, high = ans;
        bool found=false;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(f(bloomDay,mid,k)>=m){
                ans = mid;
                found = true;
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        if(found) return ans;
        return -1;
    }
};