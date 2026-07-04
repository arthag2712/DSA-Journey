/*
SIMILAR TO MEDIAN OF TWO SORTED ARRAYS (BS APPROACH)
POINT I MISSED: INITIALISATION OF LOW AND HIGH
*/
class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n1 = a.size();
        int n2 = b.size();
        if(n1 > n2) return kthElement(b,a,k);
        int low = max(0,k-n2), high = min(k,n1);
        int l1,l2,r1,r2;
        while(low <= high){
            int mid = low + (high-low)/2;
            l1 = mid-1>=0 && mid-1 < n1 ? a[mid-1] : INT_MIN;
            l2 = (k-mid-1)>=0 && (k-mid-1)<n2 ? b[k-mid-1] : INT_MIN;
            r1 = mid>=0 && mid < n1 ? a[mid] : INT_MAX;
            r2 = (k-mid)>=0 && (k-mid)<n2 ? b[k-mid] : INT_MAX;
            if(l2>r1) low=mid+1;
            else if(l1>r2) high=mid-1;
            else break;
        }
        return max(l1,l2);
    }
};