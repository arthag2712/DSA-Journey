class Solution {
public:
    //INTUITION IS TO FLATTEN THE 2D ARRAY INTO A 1D ARRAY AND APPLY SEARCH
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = (m*n)-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int el = matrix[mid/n][mid%n];
            if(target < el) r = mid-1;
            else if(target > el) l = mid+1;
            else return true;
        }
        return false;
    }
};