class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxs = 0;
        for(auto num : st){
            int start;
            if(st.find(num-1) == st.end()){
                start = num; // start would be the element for which num-1 isn't found
            }
            int curr_streak=1;
            while(st.find(start+1) != st.end()){
                curr_streak++; //while the sequence is contd., that is start+1 is found,
                // increment streak and start
                start++;
            }
            maxs = max(maxs,curr_streak);
        }
        return maxs;
    }
};