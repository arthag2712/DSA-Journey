#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //BASED ON PARTIONING THE TOTAL ARRAY INTO LEFT HALF AND RIGHT HALF
        /*
        Size of one half = (n1+n2+1)/2 as it accounts for both even and odd cases for (n1+n2), let's say 'p_size'
        Eg: nums1(n1) = {1,2,3,3,4}, n2 = {2,3,6,6,9} => p_size = 5
            NOW SPLIT CASES DEPENDING ON HOW MANY ELEMENTS TO CHOOSE FROM SMALLER ARRAY (LESSER TC)
            Cx => CHOOSE x ELEMENTS FROM n1 and (p_size-x) from n2 for the left half and vice versa for second half
            C0 => LH =  {}          | {1,2,3,3,4}
                        {2,3,6,6,9} | {}
            So checking is to be done like if both halves are written in sorted order then the max from the left should be
            less than the max from the right (will devise a condition for this later)

            C1 => LH =        {1}   | {2,3,3,4} INVALID
                        {2,3,6,6}   | {9}

            C2 => LH =    {1,2}     | {3,3,4}   INVALID
                        {2,3,6}     | {6,9}

            C3 => LH =  {1,2,3}     | {3,4}     VALID
                          {2,3}     | {6,6,9}
                          
            C4 => LH =  {1,2,3,3}   | {4}       VALID
                              {2}   | {3,6,6,9}

            C5 => LH =  {1,2,3,3,4} | {}
                                 {} | {2,3,6,6,9} INVALID

            SO BY OBSERVATION OF ALL THE CASES: WE SEE THAT if(l2>r1) the valid case lies ahead (C1 for eg.)
            so trim the search space from left, else if(l1>r2) the valid case lies behind (C5 for eg.)
            so trim the search space from the right.
            
            Finally mid will be at the indices of right, so median would be:
                a) For even (max(l1,l2)+min(r1,r2))/2.0
                b) For odd  (max(l1,l2))
        */
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1); //IMP
        int p_size = (n1+n2+1)/2;
        int low = 0, high = min(n1,n2),mid;
        int l1 = INT_MIN, l2= INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        while(low <= high){
            mid = low + (high-low)/2;
            l1 = (mid-1)>=0 && (mid-1)<n1? nums1[mid-1] : INT_MIN;
            l2 = (p_size-mid-1)>=0 && (p_size-mid-1)<n2 ? nums2[p_size-mid-1] : INT_MIN;
            r1 = (mid>=0 && mid<n1) ? nums1[mid] : INT_MAX;
            r2 = (p_size-mid)>=0 && (p_size-mid)<n2 ? nums2[p_size-mid] : INT_MAX;
            if(l2>r1) low=mid+1;
            else if(l1>r2) high=mid-1;
            else break;
        }
        if((n1+n2)%2==0){
            return (double)(max(l1,l2)+min(r1,r2))/2.0;
        }else{
            return max(l1,l2);
        }
    }
};