class Solution {
public:
    int func(int mid,int n,int m){
        long long prod=1;
        for(int i=1;i<=n;i++){
            prod*=mid;
            if(prod>m) return 2;
        }
        if(prod == m) return 0; //very important to write this outside the loop
        //otherwise intermediate power would be allowed
        return 1;
    }
    int NthRoot(int N, int M) {
        int low =1, high = M;
        int mid;
        while(low<=high){
            mid = low + (high-low)/2;
            if(func(mid, N, M)==0) return mid;
            else if(func(mid, N, M)==1) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};
