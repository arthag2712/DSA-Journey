class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        int steps=0;
        int farthest=0;
        while(j<n-1){ //necessary to stop before last index else extra 'step' is performed
            for(int k=i;k<=j;k++)
                farthest = max(farthest,k+nums[k]);
            i = j+1;
            j=farthest;
            steps++;
        }
        return steps;
    }
};
